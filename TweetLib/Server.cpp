#include "Server.h"

namespace tweet {

	grpc::Status Server::Tweet(
		grpc::ServerContext* context, 
		const proto::TweetIn* request, 
		proto::TweetOut* response)
	{
        const grpc::string peer = context->peer();
        const bool valid = storage_->Tweet(peer, request->content());
		response->set_error(!valid);
		return grpc::Status::OK;
	}

	grpc::Status Server::Follow(
		grpc::ServerContext* context, 
		const proto::FollowIn* request, 
		proto::FollowOut* response)
	{
        const grpc::string peer = context->peer();
        const bool valid = storage_->Follow(peer, request->name());
		response->set_error(!valid);
		return grpc::Status::OK;
	}

	grpc::Status Server::Show(
		grpc::ServerContext* context, 
		const proto::ShowIn* request, 
		proto::ShowOut* response)
	{
        const grpc::string peer = context->peer();
		const std::vector<TweetValue> tweets = storage_->Show(peer, request->user());
        for (const TweetValue& tweet : tweets) {
			proto::TweetIn tweetIn;
			tweetIn.set_user(tweet.name);
			tweetIn.set_content(tweet.text);
			tweetIn.set_time(tweet.time);
			*response->add_tweets() = tweetIn;
        }
		return grpc::Status::OK;
	}

	grpc::Status Server::Login(
		grpc::ServerContext* context, 
		const proto::LoginIn* request, 
		proto::LoginOut* response)
	{
        const grpc::string peer = context->peer();
        const bool valid = storage_->Login(peer,request->user(), request->pass());
		response->set_error(!valid);
		return grpc::Status::OK;
	}

	grpc::Status Server::Logout(
		grpc::ServerContext* context, 
		const proto::LogoutIn* request, 
		proto::LogoutOut* response)
	{
        const grpc::string peer = context->peer();
        const bool valid = storage_->Logout(peer);
		response->set_error(!valid);
		return grpc::Status::OK;
	}

	grpc::Status Server::Register(
		grpc::ServerContext* context, 
		const proto::RegisterIn* request, 
		proto::RegisterOut* response)
	{
        const grpc::string peer = context->peer();
        const bool valid = storage_->Register(peer, request->name(), request->pass());
		response->set_error(!valid);
		return grpc::Status::OK;
	}

} // End namespace tweet.

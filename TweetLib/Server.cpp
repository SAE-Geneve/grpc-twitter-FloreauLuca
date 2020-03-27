#include "Server.h"

namespace tweet {

	grpc::Status Server::Tweet(
		grpc::ServerContext* context, 
		const proto::TweetIn* request, 
		proto::TweetOut* response)
	{
#pragma message ("You have to complete this code!")
		grpc::string peer = context->peer();
		bool error = storage_->Tweet(peer, request->content());
		response->set_error(error);
		return grpc::Status::OK;
	}

	grpc::Status Server::Follow(
		grpc::ServerContext* context, 
		const proto::FollowIn* request, 
		proto::FollowOut* response)
	{
#pragma message ("You have to complete this code!")
		grpc::string peer = context->peer();
		bool error = storage_->Follow(peer, request->name());
		response->set_error(error);
		return grpc::Status::OK;
	}

	grpc::Status Server::Show(
		grpc::ServerContext* context, 
		const proto::ShowIn* request, 
		proto::ShowOut* response)
	{
#pragma message ("You have to complete this code!")
		grpc::string peer = context->peer();
		storage_->Show(peer, request->user());
		return grpc::Status::OK;
	}

	grpc::Status Server::Login(
		grpc::ServerContext* context, 
		const proto::LoginIn* request, 
		proto::LoginOut* response)
	{
#pragma message ("You have to complete this code!")
		grpc::string peer = context->peer();
		bool error = storage_->Login(peer,request->user(), request->pass());
		response->set_error(error);
		return grpc::Status::OK;
	}

	grpc::Status Server::Logout(
		grpc::ServerContext* context, 
		const proto::LogoutIn* request, 
		proto::LogoutOut* response)
	{
#pragma message ("You have to complete this code!")
		grpc::string peer = context->peer();
		bool error = storage_->Logout(peer);
		response->set_error(error);
		return grpc::Status::OK;
	}

	grpc::Status Server::Register(
		grpc::ServerContext* context, 
		const proto::RegisterIn* request, 
		proto::RegisterOut* response)
	{
#pragma message ("You have to complete this code!")
		grpc::string peer = context->peer();
		bool error = storage_->Register(peer, request->name(), request->pass());
		response->set_error(error);
		return grpc::Status::OK;
	}

} // End namespace tweet.

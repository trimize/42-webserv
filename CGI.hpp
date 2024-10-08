/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:40:33 by svydrina          #+#    #+#             */
/*   Updated: 2024/10/02 20:45:36 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CGI_HPP
#define CGI_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <map>
#include <unistd.h>
#include <sys/wait.h>
#include "Request.hpp"
#include "Enums.hpp"
#include "Response.hpp"
#include <sys/stat.h>

#define BufferSize 1024

class Request;
class Response;

class CGI
{
private:
	std::map<std::string, std::string> _env;
	std::string _path;
	Request * _req;
	bool	correct_path;

public:
	CGI(/* args */);
	CGI(Request * req, std::string path);
	CGI(const CGI &copy);
	CGI &operator=(const CGI &copy);
	~CGI();
	bool	isExecutable(const std::string& filePath);
	std::string	getPath();
	std::map<std::string, std::string> getEnv() const;
	
	char** env_map_to_string(); 
	Response * executeCGI();
};

#endif

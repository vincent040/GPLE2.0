//////////////////////////////////////////////////////////////////
//
//  Copyright(C), 2013-2016, GEC Tech. Co., Ltd.
//
//  File name: GPLE/ch05/5.3/fifo/Jack.c
//
//  Author: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  Date: 2016-3
//  
//  Description: 使用命名管道FIFO，实现两个进程间通信
//
//  GitHub: github.com/vincent040   Bug Report: 2437231462@qq.com
//
//////////////////////////////////////////////////////////////////

#include "head4fifo.h"

int main(int argc, char **argv)
{
	if(access(FIFO, F_OK))
	{
		mkfifo(FIFO, 0644);
	}

	int fifo = open(FIFO, O_WRONLY);
	
	char msg[20];
	bzero(msg, 20);

	fgets(msg, 20, stdin);
	int n = write(fifo, msg, strlen(msg));

	printf("%d bytes have been sended.\n", n);
	return 0;
}

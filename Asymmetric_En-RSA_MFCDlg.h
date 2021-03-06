
// Asymmetric_En-RSA_MFCDlg.h: 头文件
//
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/err.h>
#include <string.h>
#include<stdio.h>
#include <openssl/rand.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <iostream>
#include <cstringt.h>
#include <stdlib.h>
#pragma once
#define Maxlength 100

// CAsymmetricEnRSAMFCDlg 对话框
class CAsymmetricEnRSAMFCDlg : public CDialogEx
{
// 构造
public:
	CAsymmetricEnRSAMFCDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ASYMMETRIC_ENRSA_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


public:
       char *PK_path[Maxlength];
	 void ReadPubKey(const char *filep, EVP_PKEY *Pubkey);
	 void envelope_seal(EVP_PKEY *(*pub_key), unsigned char *plain_P, unsigned char *cipher_p);
	 void digest_message(char *path, unsigned char * digest, unsigned int *digest_len);
	 void ReadPriKey(const char * fileP, EVP_PKEY *PriKey);
	 void envelope_open(EVP_PKEY *priv_key, unsigned char *cipher_P, unsigned char *plain_P,unsigned char * digest);
	 int Checkout(unsigned char * Digest, unsigned char * digest);
	 int getFileSizeSystemCall(char * strFileName);
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	int Key_num;
	CString Ciphertext_P;
	CString E_Cipher_P;
	CString D_Cipher_P;
	CString Pliantext_P;
	CString PrriKey_P;
	CString Password;
	CString PubKey_P;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton8();
	double F_size1;
	double time1;
	double V1;
	double V2;
	double time2;
	double F_size2;
};


// Asymmetric_En-RSA_MFCDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Asymmetric_En-RSA_MFC.h"
#include "Asymmetric_En-RSA_MFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAsymmetricEnRSAMFCDlg 对话框



CAsymmetricEnRSAMFCDlg::CAsymmetricEnRSAMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ASYMMETRIC_ENRSA_MFC_DIALOG, pParent)
	, Key_num(0)
	, Ciphertext_P(_T(""))
	, E_Cipher_P(_T(""))
	, D_Cipher_P(_T(""))
	, Pliantext_P(_T(""))
	, PrriKey_P(_T(""))
	, Password(_T(""))
	, PubKey_P(_T(""))
	, F_size1(0)
	, time1(0)
	, V1(0)
	, V2(0)
	, time2(0)
	, F_size2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAsymmetricEnRSAMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT4, Key_num);
	DDV_MinMaxInt(pDX, Key_num, 0, 100000);
	DDX_Text(pDX, IDC_EDIT1, Ciphertext_P);
	DDX_Text(pDX, IDC_EDIT2, E_Cipher_P);
	DDX_Text(pDX, IDC_EDIT5, D_Cipher_P);
	DDX_Text(pDX, IDC_EDIT6, Pliantext_P);
	DDX_Text(pDX, IDC_EDIT7, PrriKey_P);
	DDX_Text(pDX, IDC_EDIT8, Password);
	DDX_Text(pDX, IDC_EDIT3, PubKey_P);
	DDX_Text(pDX, IDC_EDIT9, F_size1);
	DDX_Text(pDX, IDC_EDIT11, time1);
	DDX_Text(pDX, IDC_EDIT10, V1);
	DDX_Text(pDX, IDC_EDIT14, V2);
	DDX_Text(pDX, IDC_EDIT13, time2);
	DDX_Text(pDX, IDC_EDIT12, F_size2);
}

BEGIN_MESSAGE_MAP(CAsymmetricEnRSAMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON1, &CAsymmetricEnRSAMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAsymmetricEnRSAMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CAsymmetricEnRSAMFCDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CAsymmetricEnRSAMFCDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CAsymmetricEnRSAMFCDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON3, &CAsymmetricEnRSAMFCDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CAsymmetricEnRSAMFCDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON8, &CAsymmetricEnRSAMFCDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CAsymmetricEnRSAMFCDlg 消息处理程序

BOOL CAsymmetricEnRSAMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAsymmetricEnRSAMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAsymmetricEnRSAMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAsymmetricEnRSAMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CAsymmetricEnRSAMFCDlg::OnBnClickedButton1()   //明文路径选择
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, NULL, _T("*.*"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("All Files (*.*)|*.*||"));
	if (dlg.DoModal() != IDOK) return;

	USES_CONVERSION;
	CString pa = dlg.GetPathName();
	char *PlainF = T2A(pa.GetBuffer(0));
	pa.ReleaseBuffer();
	int size = getFileSizeSystemCall(PlainF);
	double  size1 = size / 1024;
	//获取文件的绝对路径 
	UpdateData();
	Ciphertext_P= dlg.GetPathName();
	F_size1 = size1;
	UpdateData(FALSE);



}
int  CAsymmetricEnRSAMFCDlg::getFileSizeSystemCall(char * strFileName)
{
	struct stat temp;
	stat(strFileName, &temp);
	return temp.st_size;
}


void CAsymmetricEnRSAMFCDlg::OnBnClickedButton2()      //密文保存路径
{
	// TODO: 在此添加控件通知处理程序代码

	BROWSEINFO bi;
	TCHAR path[MAX_PATH];
	ITEMIDLIST *pidl;
	//  
	bi.hwndOwner = this->m_hWnd;
	bi.pidlRoot = 0;
	bi.pszDisplayName = path;
	bi.lpszTitle = _T("请选择查找目录：");
	bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_EDITBOX | BIF_DONTGOBELOWDOMAIN;
	bi.lpfn = 0;
	bi.lParam = 0;
	bi.iImage = 0;
	if (pidl = SHBrowseForFolder(&bi))
	{
		SHGetPathFromIDList(pidl, path);
		UpdateData();
		E_Cipher_P = path;
		UpdateData(FALSE);
	}
}


void CAsymmetricEnRSAMFCDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, NULL, _T("*.*"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("All Files (*.*)|*.*||"));
	if (dlg.DoModal() != IDOK) return;
	USES_CONVERSION;
	CString pa = dlg.GetPathName();
	char *PlainF = T2A(pa.GetBuffer(0));
	pa.ReleaseBuffer();
	int size = getFileSizeSystemCall(PlainF);
	double  size1 = size / 1024;

	//获取文件的绝对路径 
	UpdateData();
	D_Cipher_P = dlg.GetPathName();
	F_size2 = size1;
	UpdateData(FALSE);
}


void CAsymmetricEnRSAMFCDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码

	BROWSEINFO bi;
	TCHAR path[MAX_PATH];
	ITEMIDLIST *pidl;
	//  
	bi.hwndOwner = this->m_hWnd;
	bi.pidlRoot = 0;
	bi.pszDisplayName = path;
	bi.lpszTitle = _T("请选择查找目录：");
	bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_EDITBOX | BIF_DONTGOBELOWDOMAIN;
	bi.lpfn = 0;
	bi.lParam = 0;
	bi.iImage = 0;
	if (pidl = SHBrowseForFolder(&bi))
	{
		SHGetPathFromIDList(pidl, path);
		UpdateData();
		Pliantext_P = path;
		UpdateData(FALSE);
	}
}


void CAsymmetricEnRSAMFCDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码

	CFileDialog dlg(TRUE, NULL, _T("*.*"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("All Files (*.*)|*.*||"));
	if (dlg.DoModal() != IDOK) return;
	//获取文件的绝对路径 
	UpdateData();
	PrriKey_P = dlg.GetPathName();
	UpdateData(FALSE);
	
}



void CAsymmetricEnRSAMFCDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, NULL, _T("*.*"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("All Files (*.*)|*.*||"));
	if (dlg.DoModal() != IDOK) return;
	//获取文件的绝对路径 
	CString st = dlg.GetPathName();

	

	USES_CONVERSION;
	char *path = T2A(st.GetBuffer(0));
	st.ReleaseBuffer();
	PK_path[Key_num] = (char *)malloc(st.GetLength()+1);
	int a = st.GetLength();
	memcpy(PK_path[Key_num], path, st.GetLength()+1);

	UpdateData();
	Key_num=Key_num+1;
	PubKey_P = PubKey_P + st + _T("\r\n");
	UpdateData(FALSE);

}


void CAsymmetricEnRSAMFCDlg::OnBnClickedButton4()   //加密
{
	// TODO: 在此添加控件通知处理程序代码
	clock_t start, finish;
	start = clock();
	EVP_PKEY *pkey[Maxlength];

	for (int i = 0; i < Key_num; i++)  //读取公钥
	{
		pkey[i]= EVP_PKEY_new();
	 char *filep = CAsymmetricEnRSAMFCDlg::PK_path[i];
		ReadPubKey((const char *)filep, pkey[i]);
	}
	USES_CONVERSION;
	CString P = Ciphertext_P;   //明文路径
	char *plain_P = T2A(P.GetBuffer(0));
	P.ReleaseBuffer();

	CString path = Ciphertext_P;                       //解密好的明文保存路径
	int local = path.ReverseFind('.');
	int len = path.GetLength();
	path.Delete(0, local);
	CString name("\\Encrypt");
	CString Path = E_Cipher_P + name + path;
	//进行转换
	char *cipher_P = T2A(Path.GetBuffer(0));
	Path.ReleaseBuffer();

	envelope_seal(pkey, (unsigned char *)plain_P, (unsigned char *)cipher_P);
	finish = clock();
	MessageBox(_T("加密成功！"), 0, 0);
	double duration = (double)(finish - start);
	duration = duration / 1000;
	double v = (F_size1 / 1024) / duration;
	UpdateData();
	time1 = duration;
	V1 = v;
	UpdateData(FALSE);
}

void CAsymmetricEnRSAMFCDlg::ReadPubKey(const char *filep, EVP_PKEY *Pubkey)
{
	RSA *t, *rsa;
	t = RSA_new();
	FILE *rsa_pkey_file;

	rsa_pkey_file = fopen(filep, "rb");
	if (rsa_pkey_file == NULL)
	{
		MessageBox(_T("读取公钥文件出错！"), 0, 0);
		exit(0);

	}

	rsa = PEM_read_RSAPublicKey(rsa_pkey_file, &t, NULL, NULL);
	if (rsa == NULL)
	{
		MessageBox(_T("读取公钥文件出错！！"), 0, 0);
		exit(0);

	}
	//if (!EVP_PKEY_set1_RSA(Pubkey, rsa))
	if (!EVP_PKEY_assign_RSA(Pubkey, RSAPublicKey_dup(rsa)))
	{
		MessageBox(_T("读取公钥文件出错！！"), 0, 0);
		exit(0);

	}

	RSA_free(t);
	fclose(rsa_pkey_file);
}


void CAsymmetricEnRSAMFCDlg::envelope_seal(EVP_PKEY *(*pub_key), unsigned char *plain_P, unsigned char *cipher_p)
{
	EVP_CIPHER_CTX *ctx;
	unsigned char iv[EVP_MAX_IV_LENGTH];         //初始向量
	unsigned char *encrypted_key[Maxlength];
	int encrypted_key_len[Maxlength];
	unsigned char ciphertext[1184];  //保存密文的缓冲区
	unsigned char plaintext[1184];   //保存原文的缓冲区
	int plaintext_len = 0;
	int len = 0;

	int nk = 3;
	//初始化
	for (int i = 0; i < Key_num; i++)
	{
		encrypted_key_len[i] = EVP_PKEY_size(pub_key[i]);
		encrypted_key[i] = (unsigned char *)malloc(encrypted_key_len[i]);
		
	}


	FILE *fpIn;
	FILE *fpOut;
	//打开加密文件
	fpIn = fopen((const char *)plain_P, "rb");
	if (fpIn == NULL)
	{
		MessageBox(_T("打开明文文件出错！"), 0, 0);
		exit(0);
	}
	//打开保存明文的文件
	fpOut = fopen((const char *)cipher_p, "wb");
	if (fpOut == NULL)
	{

		fclose(fpIn);
		MessageBox(_T("打开密文文件出错！"), 0, 0);
		exit(0);
	}



	/* Create and initialise the context */
	if (!(ctx = EVP_CIPHER_CTX_new()))
	{
		MessageBox(_T("创建加密上下文出错！"), 0, 0);
		exit(0);
	}
	

	/* Initialise the envelope seal operation. This operation generates
	 * a key for the provided cipher, and then encrypts that key a number
	 * of times (one for each public key provided in the pub_key array). In
	 * this example the array size is just one. This operation also
	 * generates an IV and places it in iv. */
	if (!(EVP_SealInit(ctx, EVP_aes_256_cbc(), encrypted_key, encrypted_key_len, iv, pub_key, Key_num)))
	{
		MessageBox(_T("EVP_SealInit出错！"), 0, 0);
		exit(0);
	}



	/* Provide the message to be encrypted, and obtain the encrypted output.
	 * EVP_SealUpdate can be called multiple times if necessary
	 */
	unsigned int digest_len=0;
	unsigned char * digest = (unsigned char *)OPENSSL_malloc(EVP_MD_size(EVP_sha256()));
	uint32_t eklen_n;


	eklen_n = htonl(Key_num);                    //使用公钥数量
	fwrite(&eklen_n, 1, sizeof eklen_n, fpOut);


	for (int i = 0; i < Key_num; i++)
	{
		eklen_n = htonl(encrypted_key_len[i]);      
		fwrite(&eklen_n, 1, sizeof eklen_n, fpOut);                  //encrypted_key
		fwrite(encrypted_key[i], 1, encrypted_key_len[i], fpOut);

		digest_message(PK_path[i], digest, &digest_len);     
		fwrite(digest, 1, digest_len, fpOut);

	}
	fwrite(iv, 1, EVP_CIPHER_iv_length(EVP_aes_128_cbc()), fpOut);               //iv


	int line = 0;
	for (;;)
	{
		plaintext_len = fread(plaintext, 1, 1024, fpIn);
		if (plaintext_len <= 0)//读取原文结束
			break;

		if (1 != EVP_SealUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
		{
			MessageBox(_T("加密出错！"), 0, 0);
			exit(0);
		}
		fwrite(ciphertext, 1, len, fpOut);//保存密文到文件
		line = len;
	}



	/* Finalise the encryption. Further ciphertext bytes may be written at
	 * this stage.
	 */

	if (1 != EVP_SealFinal(ctx, ciphertext + len, &len))
	{
		MessageBox(_T("EVP_SealFinal出错！"), 0, 0);
		exit(0);
	}

	fwrite(ciphertext + line, 1, len, fpOut);//保存密文到文件



	/* Clean up */
	EVP_CIPHER_CTX_free(ctx);
	fclose(fpIn);
	fclose(fpOut);

}



void CAsymmetricEnRSAMFCDlg::digest_message(char *path, unsigned char * digest, unsigned int *digest_len)
{
	EVP_MD_CTX *mdctx;
	unsigned char message[2048];
	int message_len = 0;
	
	if ((mdctx = EVP_MD_CTX_create()) == NULL)
		EVP_MD_CTX *mdctx;

	if ((mdctx = EVP_MD_CTX_create()) == NULL)
	{
		MessageBox(_T("EVP_MD_CTX_create()出错！"), 0, 0);
		exit(0);
	}

	if (1 != EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL))
	{
		MessageBox(_T("消息摘要初始化出错！"), 0, 0);
		exit(0);
	}
	FILE *fpIn;
	fpIn = fopen((const char *)path, "rb");
	if (fpIn == NULL)
	{
	
			MessageBox(_T("打开进行消息摘要的文件出错！"), 0, 0);
			exit(0);
	

	}
	for (;;)
	{

		message_len = fread(message, 1, 2048, fpIn);
		if (message_len <= 0)//读取原文结束
			break;
		if (1 != EVP_DigestUpdate(mdctx, message, message_len))
		{
			MessageBox(_T("EVP_DigestUpdate出错！"), 0, 0);
			exit(0);
		}

	}

	if (1 != EVP_DigestFinal_ex(mdctx, digest, digest_len))
	{
		MessageBox(_T("EVP_DigestFinal_ex（）出错！"), 0, 0);
		exit(0);
	};

	EVP_MD_CTX_destroy(mdctx);
	fclose(fpIn);
}

void CAsymmetricEnRSAMFCDlg::OnBnClickedButton8()
{

	UpdateData();
	
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码

	clock_t start, finish;
	start = clock();
	EVP_PKEY *priv_key;
	priv_key = EVP_PKEY_new();

	USES_CONVERSION;
	CString P = D_Cipher_P;   //明文路径
	char *Cipher = T2A(P.GetBuffer(0));
	P.ReleaseBuffer();

	CString path = D_Cipher_P;                       //解密好的明文保存路径
	int local = path.ReverseFind('.');
	int len = path.GetLength();
	path.Delete(0, local);
	CString name("\\Decryt_F");
	CString Path = Pliantext_P + name + path;
	//进行转换
	char *plain_P = T2A(Path.GetBuffer(0));
	Path.ReleaseBuffer();

	CString Prikey = PrriKey_P;   //明文路径
	char *prk = T2A(Prikey.GetBuffer(0));
	Prikey.ReleaseBuffer();

	ReadPriKey(prk, priv_key);
	



	//使用系统指令生成一个摘要信息
	CString  path1 = PrriKey_P.Left(2);;          //D:
	

	char c = 92;
	CString path2 = PrriKey_P;
	int local2 = path2.ReverseFind(c);
	int len2 = path2.GetLength();
	path2= PrriKey_P.Left(local2);
	CString Digest=path2 + _T("\\pubkeyNew.pem");
	path2 = _T("cd ") + path2;
	

	int len3 = len2 - local2-1;
	CString path3 = PrriKey_P.Right(len3);


	CString PK_M;
	PK_M = path1 + _T("&") + path2 + _T("&") + _T("openssl rsa -in ") + path3 + _T(" -passin pass:") + Password + _T(" -out pubkeyNew.pem -RSAPublicKey_out");

	char *pk_cmd= T2A(PK_M.GetBuffer(0));
	PK_M.ReleaseBuffer();

	system(pk_cmd); //生成新的公钥文件


	//获取摘要信息
	char *digest_path= T2A(Digest.GetBuffer(0));
	Digest.ReleaseBuffer();
	unsigned int digest_len = 0;
	unsigned char * digest = (unsigned char *)OPENSSL_malloc(EVP_MD_size(EVP_sha256()));
	digest_message(digest_path, digest, &digest_len);


	CString del_file;                                          //删除新生成的公钥文件
	del_file = Digest;
	char *del= T2A(del_file.GetBuffer(0));
	del_file.ReleaseBuffer();
	remove(del);

	//解密
   envelope_open(priv_key, (unsigned char *)Cipher, (unsigned char *)plain_P, digest);
   finish = clock();
   MessageBox(_T("解密成功！"), 0, 0);
   double duration = (double)(finish - start);
   duration = duration / 1000;
   double v = (F_size2 / 1024) / duration;
   UpdateData();
   time2 = duration;
   V2 = v;
   UpdateData(FALSE);
	

}

void CAsymmetricEnRSAMFCDlg::ReadPriKey(const char * fileP, EVP_PKEY *PriKey)
{

	RSA *t, *rsa;
	t = RSA_new();
	FILE *rsa_pkey_file;
	USES_CONVERSION;
	CString P = Password;  
	char *passwod = T2A(P.GetBuffer(0));
	P.ReleaseBuffer();
	rsa_pkey_file = fopen((const char *)fileP, "rb");
	if (rsa_pkey_file == NULL)
	{
		MessageBox(_T("私钥文件打开出错！"), 0, 0);
		exit(0);

	}
	OpenSSL_add_all_algorithms();

	rsa = PEM_read_RSAPrivateKey(rsa_pkey_file, &t, NULL, passwod);
	if (rsa == NULL)
	{
		fclose(rsa_pkey_file);
		MessageBox(_T("读取私钥出错！"), 0, 0);
		exit(0);;

	}
	if (!EVP_PKEY_assign_RSA(PriKey, RSAPrivateKey_dup(rsa)))
	{
		MessageBox(_T("读取私钥出错！"), 0, 0);
		exit(0);

	}
	RSA_free(t);
	fclose(rsa_pkey_file);
}

void CAsymmetricEnRSAMFCDlg::envelope_open(EVP_PKEY *priv_key, unsigned char *cipher_P, unsigned char *plain_P, unsigned char * digest)
{
	EVP_CIPHER_CTX *ctx;
	unsigned char ciphertext[1184];  //保存密文的缓冲区
	unsigned char plaintext[1184];   //保存原文的缓冲区
	int ciphertext_len = 0;
	uint32_t eklen_n;
	int len = 0;
	unsigned char iv[EVP_MAX_IV_LENGTH];         //初始向量
	unsigned char *ekey[Maxlength];
	int ekey_len[Maxlength];
	unsigned char * Digest[Maxlength];
	
	FILE *fpIn;
	FILE *fpOut;
	//打开加密文件
	fpIn = fopen((const char *)cipher_P, "rb");
	if (fpIn == NULL)
	{
		MessageBox(_T("打开文件出错！"), 0, 0);
		exit(0);
	}
	//打开保存明文的文件
	fpOut = fopen((const char *)plain_P, "wb");
	if (fpOut == NULL)
	{

		MessageBox(_T("打开文件出错！"), 0, 0);
		exit(0);
	}

	int n = 0;
	int ck = 0;
	int K_num = 0;
	fread(&eklen_n, 1, sizeof eklen_n, fpIn);   //读出使用的公钥数目
    K_num = ntohl(eklen_n);

	for (int i = 0; i < K_num; i++)
	{
		fread(&eklen_n, 1, sizeof eklen_n, fpIn);         
		ekey_len[i] = ntohl(eklen_n);
		
		if (ekey_len[i] > EVP_PKEY_size(priv_key))
		{
			MessageBox(_T("读取公钥长度出错！"), 0, 0);
			exit(0);
		}
		ekey[i] = (unsigned char *)malloc(ekey_len[i]);      
		fread(ekey[i], 1, ekey_len[i], fpIn);


		 Digest[i] = (unsigned char *)OPENSSL_malloc(EVP_MD_size(EVP_sha256()));   //取出对应的消息摘要
		 fread(Digest[i], 1, EVP_MD_size(EVP_sha256()), fpIn);
		 ck = Checkout(Digest[i], digest);
		 if(1==ck)  n=i;          
		
	}

	fread(iv, 1, EVP_CIPHER_iv_length(EVP_aes_128_cbc()), fpIn);

	unsigned char *encrypted_key;
	int encrypted_key_len = ekey_len[n];
	encrypted_key = (unsigned char *)malloc(encrypted_key_len);
	encrypted_key = ekey[n];

	/* Create and initialise the context */
	if (!(ctx = EVP_CIPHER_CTX_new()))
	{
		MessageBox(_T("初始化密文上下文出错！"), 0, 0);
		exit(0);

	}

		/* Initialise the decryption operation. The asymmetric private key is
		 * provided and priv_key, whilst the encrypted session key is held in
		 * encrypted_key */
		if (!EVP_OpenInit(ctx, EVP_aes_256_cbc(), encrypted_key, encrypted_key_len, iv, priv_key)) {
			MessageBox(_T("EVP_OpenInit出错！"), 0, 0);
			exit(0);

		}


	/* Provide the message to be decrypted, and obtain the plaintext output.
	 * EVP_OpenUpdate can be called multiple times if necessary
	 */

	int line = 0;
	for (;;)
	{
		ciphertext_len = fread(ciphertext, 1, 1024, fpIn);
		if (ciphertext_len <= 0)//读取原文结束
			break;

		if (1 != EVP_OpenUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) {

			MessageBox(_T("EVP_OpenUpdate出错！"), 0, 0);
			exit(0);

		}

		fwrite(plaintext, 1, len, fpOut);//保存密文到文件
		line = len;
	}

	/* Finalise the decryption. Further plaintext bytes may be written at
	 * this stage.
	 */
	if (1 != EVP_OpenFinal(ctx, plaintext + len, &len)) {
		MessageBox(_T("EVP_OpenFinal出错！"), 0, 0);
		exit(0);

	}


	fwrite(plaintext + line, 1, len, fpOut);//保存密文到文件

	/* Clean up */
	EVP_CIPHER_CTX_free(ctx);
	fclose(fpIn);
	fclose(fpOut);
}
int CAsymmetricEnRSAMFCDlg::Checkout(unsigned char * Digest, unsigned char * digest)
{

	int num = 0;
	char H[3] = { '0' };
	int j = 0;
	CString st;
	int digest_len = EVP_MD_size(EVP_sha256());
	for (int i = 0; i < digest_len; i++)
	{
		num = digest[i];
		itoa(num, H, 16);
		if (H[1] == '\0')
		{
			H[1] = H[0];
			H[0] = '0';

		}
		st = st + H[0] + H[1];
	}
	CString st1;
	for (int i = 0; i < digest_len; i++)
	{
		num = Digest[i];
		itoa(num, H, 16);
		if (H[1] == '\0')
		{
			H[1] = H[0];
			H[0] = '0';

		}
		st1 = st1 + H[0] + H[1];
	}
	if (st == st1) return 1;
	else return 0;

}


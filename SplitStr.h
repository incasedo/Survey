
class CSplitStr
{
private:
//�зֵı�־����
CString m_sSplitFlag;
//�������зֵı�־���ŵ���һ����־����
BOOL m_bSequenceAsOne;
//���зֵ��ı�
CString m_sData;
public:
//�õ��зֺõ��ı���
void GetSplitStrArray(CStringArray &array);
//�õ����зֵ��ı�
CString GetData();
//���ñ��зֵ��ı�
void SetData(CString sData);
//�õ��зֲ���
BOOL GetSequenceAsOne() {return m_bSequenceAsOne;};
//�����зֲ���
void SetSequenceAsOne(BOOL bSequenceAsOne) {m_bSequenceAsOne = bSequenceAsOne;};
//�õ��зֱ�־
CString GetSplitFlag() {return m_sSplitFlag;};
//�����зֱ�־
void SetSplitFlag(CString sSplitFlag) {m_sSplitFlag = sSplitFlag;};

CSplitStr();
virtual ~CSplitStr();
};

// Created by aeddy@2003/01/20 �����ܵ���
// �κ�������·��ʱ�ϸ�ע�ⲻҪ�ظ�����Ҫд��
// ����ע��ϵͳ���͡�����ROOM���ڴ��ļ����
// ��Ӽ̳�����󣬷�����ע��ɾ�� inherit ROOM 
// dĿ¼�·���Ҳ����CITY_OBֱ�ӵ���

#include <command.h>
#include <mudlib.h>
string day_event(){return NATURE_D->outdoor_room_event();}

#define DROOM			"/d/room/"
#define DNPC			"/d/npc/"
#define DOBJ			"/d/obj/"

//���Ƴ���
//#define CITY		"/d/city/"		/*Ĭ�ϳ��������䣬���ⷿ�䲻�ܷ���������*/
//#define CITY_ROOM		"/d/city/room/"	/*Ĭ�ϳ������ⷿ�䣬���ڷ��벻���ù���ֲ���ROOM*/
//#define CITY_NPC		"/d/city/npc/"	/*Ĭ�����������NpcĿ¼*/
//#define CITY_OBJ		"/d/city/obj/"	/*Ĭ�����������ObjectĿ¼*/

//���Ƴ���
#define CITY_ROOM		"/d/city/"
#define CITY_NPC		"/d/city/npc/"
#define CITY_OBJ		"/d/city/obj/"

//��������
#define CAS_ROOM		"/d/changan/"
#define CAS_NPC		"/d/changan/npc/"
#define CAS_OBJ		"/d/changan/obj/"

//�����Զ�
#define CAE_ROOM		"/d/eastway/"
#define CAE_NPC		"/d/eastway/npc/"
#define CAE_OBJ		"/d/eastway/obj/"

//��������
#define CAW_ROOM		"/d/westway/"
#define CAW_NPC		"/d/westway/npc/"
#define CAW_OBJ		"/d/westway/obj/"

//����
#define KAIFENG		"/d/kaifeng/"
#define KAIFENG_ROOM		"/d/kaifeng/room/"
#define KAIFENG_NPC		"/d/kaifeng/npc/"
#define KAIFENG_OBJ		"/d/kaifeng/obj/"

//���ݳ�(ȡ��)
#define JZC_ROOM		"/d/jz/"
#define JZC_NPC		"/d/jz/npc/"
#define JZC_OBJ		"/d/jz/obj/"

//�����¹�(����)
#define MOON_ROOM		"/d/moon/"
#define MOON_NPC		"/d/moon/npc/"
#define MOON_OBJ		"/d/moon/obj/"

//����ׯ(ȡ��)
#define GLZ_ROOM		"/d/gao/"
#define GLZ_NPC		"/d/gao/npc/"
#define GLZ_OBJ		"/d/gao/obj/"

//���޵ظ�(����)(ȡ��)(�����칬)
#define DIFU_ROOM		"/d/death/"
#define DIFU_NPC		"/d/death/npc/"
#define DIFU_OBJ		"/d/death/obj/"

//�칬1
#define SKY1_ROOM		"/d/sky/"
#define SKY1_NPC		"/d/sky/npc/"
#define SKY1_OBJ		"/d/sky/obj/"

//�칬2
#define SKY2_ROOM		"/d/dntg/sky/"
#define SKY2_NPC		"/d/dntg/sky/npc/"
#define SKY2_OBJ		"/d/dntg/sky/obj/"

//�칬3
#define DNTG_ROOM		"/d/dntg/yunlou/"
#define DNTG_NPC		"/d/dntg/yunlou/npc/"
#define DNTG_OBJ		"/d/dntg/yunlou/obj/"

//��ʦ(ϵͳ)
#define WIZ_ROOM		"/d/wiz/"
#define WIZ_NPC		"/d/wiz/npc/"
#define WIZ_OBJ		"/d/wiz/obj/"

//��ʦ/U/aeddy(ϵͳ)
#define WAI_ROOM		"/u/aeddy/"
#define WAI_NPC		"/u/aeddy/npc/"
#define WAI_OBJ		"/u/aeddy/obj/"
#define WAIROOM		"/u/aeddy/room/auroom"

//��ʦ/U/ALWAYS(ϵͳ)
#define AWS_ROOM		"/u/always/"
#define AWS_NPC		"/u/always/npc/"
#define AWS_OBJ		"/u/always/obj/"

//������� /U/BANGHUI(ϵͳ)
#define UBH_ROOM		"/u/banghui/"
#define UBH_NPC		"/u/banghui/npc/"
#define UBH_OBJ		"/u/banghui/obj/"

//���Ŵ�ѩɽ(����)
#define DXS_ROOM		"/d/xueshan/"
#define DXS_NPC		"/d/xueshan/npc/"
#define DXS_OBJ		"/d/xueshan/obj/"

//��������(�����칬)(����)
#define SEAE_ROOM		"/d/sea/"
#define SEAE_NPC		"/d/sea/npc/"
#define SEAE_OBJ		"/d/sea/obj/"
 
//��������(ȡ��)
#define SEAW_ROOM		"/d/qujing/xihai/"
#define SEAW_NPC		"/d/qujing/xihai/npc/"
#define SEAW_OBJ		"/d/qujing/xihai/obj/"

//�Ϻ�����(��δ����)
#define SEAS_ROOM		"/d/seas/"
#define SEAS_NPC		"/d/seas/npc/"
#define SEAS_OBJ		"/d/seas/obj/"

//��������(��δ����)
#define SEAN_ROOM		"/d/sean/"
#define SEAN_NPC		"/d/sean/npc/"
#define SEAN_OBJ		"/d/sean/obj/"

//��̨����ɽ(����)
#define LTFC_ROOM		"/d/lingtai/"
#define LTFC_NPC		"/d/lingtai/npc/"
#define LTFC_OBJ		"/d/lingtai/obj/"

//÷ɽ
#define MEI_ROOM		"/d/meishan/"
#define MEI_NPC		"/d/meishan/npc/"
#define MEI_OBJ		"/d/meishan/obj/"

//���ƻʹ�
#define HGDN_ROOM		"/d/huanggong/"
#define HGDN_NPC		"/d/huanggong/npc/"
#define HGDN_OBJ		"/d/huanggong/obj/"

//����(ս��)
#define MJZY_ROOM		"/d/mingjiao/"
#define MJZY_NPC		"/d/mingjiao/npc/"
#define MJZY_OBJ		"/d/mingjiao/obj/"
 
//�Ϻ�����ɽ(����)
#define NANHAI_ROOM		"/d/nanhai/"
#define NANHAI_NPC		"/d/nanhai/npc/"
#define NANHAI_OBJ		"/d/nanhai/obj/"

//�����ɵ�
#define PENGL_ROOM		"/d/penglai/"
#define PENGL_NPC		"/d/penglai/npc/"
#define PENGL_OBJ		"/d/penglai/obj/"

//������ɽ(����)
#define SHUS_ROOM		"/d/shushan/"
#define SHUS_NPC		"/d/shushan/npc/"
#define SHUS_OBJ		"/d/shushan/obj/"

//ˮ������(����)
#define TP_ROOM		"/d/tianpeng/"
#define TP_NPC		"/d/tianpeng/npc/"
#define TP_OBJ		"/d/tianpeng/obj/"

//���ƽ�����(����)
#define JJF_ROOM		"/d/jjf/"
#define JJF_NPC		"/d/jjf/npc/"
#define JJF_OBJ		"/d/jjf/obj/"

//��˿(����)
#define PSD_ROOM		"/d/pansi/"
#define PSD_NPC		"/d/pansi/npc/"
#define PSD_OBJ		"/d/pansi/obj/"

//����̲�̶(ȡ��)(����)
#define BIBO_ROOM		"/d/qujing/bibotan/"
#define BIBO_NPC		"/d/qujing/bibotan/npc/"
#define BIBO_OBJ		"/d/qujing/bibotan/obj/"

//�������ù�(ȡ��)
#define TZG_ROOM		"/d/qujing/tianzhu/"
#define TZG_NPC		"/d/qujing/tianzhu/npc/"
#define TZG_OBJ		"/d/qujing/tianzhu/obj/"

//��ׯ��(ȡ��)(����)
#define WZG_ROOM		"/d/qujing/wuzhuang/"
#define WZG_NPC		"/d/qujing/wuzhuang/npc/"
#define WZG_OBJ		"/d/qujing/wuzhuang/obj/"

//������ƶ�(ȡ��)(����)
#define HYD_ROOM		"/d/qujing/kusong/"
#define HYD_NPC		"/d/qujing/kusong/npc/"
#define HYD_OBJ		"/d/qujing/kusong/obj/"

//������˿��(ȡ��)
#define PSL_ROOM		"/d/qujing/pansi/"
#define PSL_NPC		"/d/qujing/pansi/npc/"
#define PSL_OBJ		"/d/qujing/pansi/obj/"

//����˫����(ȡ��)
#define SCL_ROOM		"/d/qujing/shuangcha/"
#define SCL_NPC		"/d/qujing/shuangcha/npc/"
#define SCL_OBJ		"/d/qujing/shuangcha/obj/"

//������ɿ�(ȡ��)
#define FXJ_ROOM		"/d/qujing/fengxian/"
#define FXJ_NPC		"/d/qujing/fengxian/npc/"
#define FXJ_OBJ		"/d/qujing/fengxian/obj/"

//�����ɽ(ȡ��)
#define JDS_ROOM		"/d/qujing/jindou/"
#define JDS_NPC		"/d/qujing/jindou/npc/"
#define JDS_OBJ		"/d/qujing/jindou/obj/"

//��������ɽ(ȡ��)
#define YWS_ROOM		"/d/qujing/yinwu/"
#define YWS_NPC		"/d/qujing/yinwu/npc/"
#define YWS_OBJ		"/d/qujing/yinwu/obj/"

//�����շ���(ȡ��)
#define QFG_ROOM		"/d/qujing/qinfa/"
#define QFG_NPC		"/d/qujing/qinfa/npc/"
#define QFG_OBJ		"/d/qujing/qinfa/obj/"

//���������(ȡ��)
#define JSG_ROOM		"/d/qujing/jisaiguo/"
#define JSG_NPC		"/d/qujing/jisaiguo/npc/"
#define JSG_OBJ		"/d/qujing/jisaiguo/obj/"

//�����ƽ��(ȡ��)
#define JPF_ROOM		"/d/qujing/jinping/"
#define JPF_NPC		"/d/qujing/jinping/npc/"
#define JPF_OBJ		"/d/qujing/jinping/obj/"

//��������(ȡ��)
#define BQG_ROOM		"/d/qujing/biqiu/"
#define BQG_NPC		"/d/qujing/biqiu/npc/"
#define BQG_OBJ		"/d/qujing/biqiu/obj/"

//��������(ȡ��)
#define YHX_ROOM		"/d/qujing/yuhua/"
#define YHX_NPC		"/d/qujing/yuhua/npc/"
#define YHX_OBJ		"/d/qujing/yuhua/obj/"

//�������(ȡ��)
#define BXG_ROOM		"/d/qujing/baoxiang/"
#define BXG_NPC		"/d/qujing/baoxiang/npc/"
#define BXG_OBJ		"/d/qujing/baoxiang/obj/"

//�����ڼ���(ȡ��)
#define WJG_ROOM		"/d/qujing/wuji/"
#define WJG_NPC		"/d/qujing/wuji/npc/"
#define WJG_OBJ		"/d/qujing/wuji/obj/"

//���򳵳ٹ�(ȡ��)
#define CCG_ROOM		"/d/qujing/chechi/"
#define CCG_NPC		"/d/qujing/chechi/npc/"
#define CCG_OBJ		"/d/qujing/chechi/obj/"

//����ͨ���(ȡ��)
#define TTH_ROOM		"/d/qujing/tongtian/"
#define TTH_NPC		"/d/qujing/tongtian/npc/"
#define TTH_OBJ		"/d/qujing/tongtian/obj/"

//�����ˮ��(ȡ��)
#define HSH_ROOM		"/d/qujing/heishui/"
#define HSH_NPC		"/d/qujing/heishui/npc/"
#define HSH_OBJ		"/d/qujing/heishui/obj/"

//����Ů����(ȡ��)
#define NEG_ROOM		"/d/qujing/nuerguo/"
#define NEG_NPC		"/d/qujing/nuerguo/npc/"
#define NEG_OBJ		"/d/qujing/nuerguo/obj/"

//�������Ϲ�(ȡ��)
#define ZZG_ROOM		"/d/qujing/zhuzi/"
#define ZZG_NPC		"/d/qujing/zhuzi/npc/"
#define ZZG_OBJ		"/d/qujing/zhuzi/obj/"

//��������ɽ(ȡ��)
#define QLS_ROOM		"/d/qujing/qinglong/"
#define QLS_NPC		"/d/qujing/qinglong/npc/"
#define QLS_OBJ		"/d/qujing/qinglong/obj/"

//��ԯ��Ĺ(ȡ��)(����)
#define GUMU_ROOM		"/d/qujing/xuanyuan/"
#define GUMU_NPC		"/d/qujing/xuanyuan/npc/"
#define GUMU_OBJ		"/d/qujing/xuanyuan/obj/"

//����(��������)
#define MIWU			"/d/west/miwudao/"
#define MIWU_ROOM		"/d/west/miwudao/room/"
#define MIWUU_NPC		"/d/west/miwudao/npc/"
#define MIWU_OBJ		"/d/west/miwudao/obj/"

//������(��������)
#define GOLD_ROOM		"/d/tianpeng/jinyin/"
#define GOLD_NPC		"/d/tianpeng/jinyin/npc/"
#define GOLD_OBJ		"/d/tianpeng/jinyin/obj/"

//���ĺ���(��������)
#define TYHJ_ROOM		"/d/tianpeng/tianya/"
#define TYHJ_NPC		"/d/tianpeng/tianya/npc/"
#define TYHJ_OBJ		"/d/tianpeng/tianya/obj/"

//�˽���(��������)
#define BJH_ROOM		"/d/tianpeng/hu/"
#define BJH_NPC		"/d/tianpeng/hu/npc/"
#define BJH_OBJ		"/d/tianpeng/hu/obj/"

//���ڳ�(��������)
#define ANHEI_ROOM		"/d/diablo/"
#define ANHEI_NPC		"/d/diablo/npc/"
#define ANHEI_OBJ		"/d/diablo/obj/"

//�Ľ�(һ������)
#define HOME_ROOM		"/d/ourhome/"
#define HOME_NPC		"/d/ourhome/npc/"
#define HOME_OBJ		"/d/ourhome/obj/"

//Ұ��կ(NPC�������)
#define YYZ_ROOM		"/d/yeyangzhai/"
#define YYZ_NPC		"/d/yeyangzhai/npc/"
#define YYZ_OBJ		"/d/yeyangzhai/obj/"



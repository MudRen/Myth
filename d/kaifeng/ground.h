
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 2/8/1997

#include <ansi.h>

#define DEBUG 0

#define REWARD 16

#define STEP_PREPARE 0
#define STEP_FIGHT   1
#define STEP_FINISH  2

#define MODE_SINGLE_SD 0
#define MODE_SINGLE_LT 1
#define MODE_TEAM_LT   2
#define MODE_TEAM_DZ   3
#define MODE_TEAM_XH   4
string *modes = ({
  "����ɢ��",
  "������̨",
  "������̨",
  "���ɶ���",
  "����ѭ����",
});
string *mode_hints = ({
  "��������������ϳ�����",
  "��������ϳ�������������Ӯ��Ϊ������",
  "ÿ���ɵ�ѡ�������ϳ����ޣ���ѡ��Ӯ��Ϊ����������",
  "ÿ���ɵ�ѡ�ְ���ǿ�ȼ����࣬�����ɼ��ͬ��ѡ�ֽ���",
  "ÿ���ɵ�ѡ������������������ѡ�ֽ���",
});

#define FAMILY_NONE     0
#define FAMILY_FANGCUN  1
#define FAMILY_MOON     2
#define FAMILY_PUTUO    3
#define FAMILY_HELL     4
#define FAMILY_JJF      5
#define FAMILY_LONGGONG 6
#define FAMILY_WUDIDONG 7
#define FAMILY_XUESHAN  8
string *families = ({
  "�������",
  "����ɽ���Ƕ�",
  "�¹�",
  "�Ϻ�����ɽ",
  "���޵ظ�",
  "������",
  "��������",
  "�ݿ�ɽ�޵׶�",
  "��ѩɽ",
});


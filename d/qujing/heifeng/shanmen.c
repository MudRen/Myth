//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/heifeng/shanlu1.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ǰ�������Ժ���羰�续��������Ժ��ɽ��Χ�ţ�����һЩ��
����Ժ��ǽ�Ͽ��˳�����Ҳ������ǡ�һֻ���ӳ�ǽ������ԭ
�Ͱɣ�ɽ�����Ի������˸�ʯʨ�ӡ�
LONG);

  set("exits", ([
        "enter"  : __DIR__"dadian",
        "eastdown"  : __DIR__"shandao5",
        "westdown"  : "/d/qujing/yunzhan/road1",
      ]));
  set("objects",([
        __DIR__"npc/welcome": 1,
                ]));
  set("outdoors","hf");
  setup();

}

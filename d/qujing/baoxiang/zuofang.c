// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/zuofang.c

inherit ROOM;

void create ()
{
  set ("short", "С����");
  set ("long", @LONG

������ǽ�Ϲ�����ʽ�����ֹ���Ʒ��̺֯��һλ�������˽Ų�ľ֯
��֯��̺�ӡ��ݽǶ���ľͷ���һЩδ�깤�ļҾ㡣͸����������
�����������������֨ѽѽ�ط��ߡ�

LONG);

  set("exits", ([
        "west"       : __DIR__"bei3",
      ]));

  set("objects", ([ 
    __DIR__"npc/fangzhu" : 1,
  ]));
  setup();
}


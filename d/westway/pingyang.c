// create by snowcat.c 4/8/1997
// room: /d/westway/pingyang.c

inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short","ƽ����");
  set ("long", @LONG

���ѵ�ƽ����ϸϸ������ͨ��ɽ����ﰲ��������̧ͷ����
��ȥ�������һ����ɽ������ʧ���򶫱���ȥ��һ��������
���������������ȥ���������һ�þ޴�Ŀ���(tree)��

LONG);

  set("item_desc",([
    "tree" : "���Ͽ��ţ�"+
    "���������������ûɱ��Խ�������Ӷ����мǡ�\n",
  ]));

  set("exits", ([
        "northeast" : __DIR__"yongjing",
        "west"      : __DIR__"yinma",
      ]));
  set("outdoors", __DIR__);
       set("tsj_exst","west");

  setup();
}






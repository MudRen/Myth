// create by snowcat.c 4/8/1997
// room: /d/westway/dadao.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","���");
  set ("long", @LONG

����һ�������Ĵ������ԶԶ��ɽ�����ƹ�����ز�ã������
������ش��ţ�����·������ķ�ɳ��������������Ե����ˣ�
���ڴҴ�ææ�ظ���·�������ǽ�ǿ����������ٸ�һ��·��
���Ե��������ˡ�

LONG);

  set("exits", ([
        "east" : __DIR__"jincheng",
        "west" : __DIR__"yongjing",
      ]));
       set("tsj_exst","west");
   set("objects",([
 //  "/d/qujing/kusong/npc/jiruhuo" : 1,
   "/d/shendian/babu/axiuluo" : 1,
   ]));
  set("outdoors", __DIR__);

  setup();
}




//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//baicaidi.c

inherit ROOM;
#include <room.h>

void create ()
{
   set ("short", "�ײ˵�");
   set ("long", @LONG

��ׯ�����µĶ࣬�Է���Ҳ���٣����Թ��ڹ��˸�����һЩũ��
�����߲˹Ϲ��������ǰײ˵ء�
LONG);

   set("exits", 
   ([ //sizeof() == 4
     "south" : __DIR__"qiezidi",
     "northwest" : __DIR__"xiguadi",
     "north":    __DIR__"tree",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     "/d/obj/food/xbc" : 2,
   ]));
   set("outdoors", "wuzhuang");

   setup();
}

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����ƺ");
  set ("long", @LONG

������з�Բ���ɵ�һƬ�յأ��Ĵ����Ų������ܣ�����ڵ���
�̽Ṵ�����ͺ���һ�Ŵ���������ʯ���ϡ�Զ��ɽ���ϱ�صľ�
��������·����Χס��
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/guard" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jingji8",
  "southup" : __DIR__"shiya",
]));

  setup();
}


int valid_leave(object me, string dir)
{       
        object a;
        if( wizardp(me)) return 1;

        if (dir == "southup") {
                if(objectp(a=present("guard", environment(me))) &&
living(a) )
                return
notify_fail("�����ʹһͦ���иֲ棬��ס�����ȥ·��\n");
        }

        return 1;
}


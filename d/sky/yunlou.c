#include <room.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "��¥��");
  set ("long", @LONG

��¥��������������֮�����ã����������������Ԫ˧����¥��
ʵ�������֮�������ࡣ���½������������У�ɱ�����ڣ���ǰ
һ�Խ���ȼ��ָ�������
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "up" : "̨�ϰ������ƣ�ʲôҲ���������\n",
]));

  set("exits", ([ /* sizeof() == 1 */
    "up": __DIR__"yunloutai",
    "south": __DIR__"yongdao",
  ]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/julingshen" : 1,
]));

  setup();
}


int valid_leave(object me, string dir)
{       
        object a;
        if( wizardp(me)) return 1;

        if (dir == "up") {
                if(objectp(a=present("juling shen", environment(me))) && living(a) )
                return notify_fail("�����������һ�����أ�����������\n");

        return ::valid_leave(me, dir);
        }

        return 1;
}


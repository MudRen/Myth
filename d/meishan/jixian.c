
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

ɽ�ƶ�ת�ڴˣ��ѳɰ�Ķ��С��һƬƽ�ء��Ӵ�����ɽ�ߣ�����
���磬㤰����������з�â���ɱ��ӡ�����������ֻ���������
����Բ�߻�Բ���Ʒ�����������
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "northup" : "������Լ����ɽ�ߡ�\n",
]));

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/zhi" : 1,
  __DIR__"npc/guo" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"cuiping",
  "southeast" : __DIR__"zhaoyun",
]));

  setup();
}


int valid_leave(object me, string dir)
{
        if (dir == "northup" ) {
        if (objectp(present("guo shen", environment(me))))
        return notify_fail("����һ��������潣���ȵ�����Ϊ��÷ɽҪ�أ������˵�������\n");
        if (objectp(present("zhi jian", environment(me))))
        return notify_fail("ֱ������ͭ��������������������˵������������Ӧ����\n");
        }   
        return ::valid_leave(me, dir);
}


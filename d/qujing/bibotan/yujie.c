#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

һ�������̳ɵ���׽���ɳ̨��ˮ�������𡣽׵�����������ʿ
���ء�һЩ�㾫ˮ�ֳ������룬ˮ�����еƻ�ͨ�����ƺ����ھ�
�д��磬�����������꽻���������
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/bie" : 1,
  __DIR__"npc/gui" : 1,
]));
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shuijg",
  "south" : __DIR__"longtai1",
]));
//      
        set("water", 1);
//  
  setup();
}

int valid_leave(object me, string dir)
{

        if( wizardp(me)) return 1;
	if( me->query("family/master_id")=="jiutou fuma") return 1;

        if (dir == "northup" ) {
        if (objectp(present("xiboer gu", environment(me))))
        return notify_fail("���������µ��������й�ͣ����������\n");
        if (objectp(present("guboer xi", environment(me))))
        return notify_fail("�Ų������µ��������й�ͣ����������\n");
        }   
        return ::valid_leave(me, dir);
}


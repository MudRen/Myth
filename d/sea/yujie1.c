inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

�ɴ������������������������ס�����档һ������̨�׶����á�����
�����ɣ���������������ʿ���������ף�ɷ�����硣
LONG);

          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/lishi" : 2,
]));

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"huilang1.c",
  "north" : __DIR__"huilang4.c",
  "westdown" : __DIR__"inside1.c",
  "east" : __DIR__"yujie2.c",
]));
//      
        set("water", 1);
//  
  setup();
}
/*
int valid_leave(object me, string dir)
{
        if( (string)me->query("family/family_name")=="��������" ) return 1;
	if( (string)me->query("family/family_name")=="����" ) return 1;
	if( !me->query("family") ) return 1;
        if( wizardp(me)) return 1;
        if( present("yao pai", me) ) return 1;

        if (dir == "east"
	|| dir=="south" 
	|| dir=="north") {
        if (objectp(present("li shi", environment(me))))
        return notify_fail("��ǰ�������ֵ�ס�����ȥ·��\n");
        }   
        return ::valid_leave(me, dir);
}
*/


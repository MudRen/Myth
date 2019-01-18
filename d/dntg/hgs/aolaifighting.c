// Room: /d/jjf/gate.c

inherit ROOM;


void create()
{
set("short", "���䳡���");
set("long", @LONG
�ڰ��������䳡����ڣ�վ���ż�������Ľ�����ͷ��
������������治ʱ������׳�ĺŽ�����
LONG
	);

set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"fight_room",
  "west"  : __DIR__"northgate",
]));
set("out_doors", 1);
set("objects", ([ /* sizeof() == 1 */
   __DIR__"npc/jiaotou" : 2,
]));

setup();
}



int valid_leave(object me, string dir)
{
    if (dir == "south" && objectp(present("jinjun jiaotou", environment(me)))) 
      {
      if ( me->query_temp("donghai") !=1 ) 
         {
         return
         notify_fail("������ͷ�ȵ����ҹ�������������ѵ�����������ʲô(answer)��\n"
                    +"(�������䡡���������֡��������ҡ������Ӿ�)\n");
         }
      }
      else 
         { 
         return 
         ::valid_leave(me, dir); 
         }
      return 1;
}


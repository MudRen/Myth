//standroom.c used by weiqi...others may hate this format:D
//xueshan1.c

inherit ROOM;

void create ()
{
  set ("short", "ããѩ��");
  set ("long", @LONG

�����Х����ѩãã������������ȥ�������Ӳ�����ѩ�壬����ǰ�߱�Ҫ
��������������ˡ����Ϸ�������Ⱥɽ�����ֻ�Ǳ�ѩ�Ѳ������ڣ�Ҫ��
����ѩɽ�ǳɹ������ˡ�
LONG);

  set("outdoors", "xueshan");
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"xueshan3",
  "south" : __DIR__"xueshan1",
]));


  set("objects", ([ /* sizeof() == 4 */
  "/d/xueshan/npc/wuya-guai" : 1,
]));

  setup();
}

int valid_leave(object me, string dir)
{
    if (dir == "northwest" && objectp(present("wuya xiansheng", environment(me)))) 
      {
      if ( me->query_temp("to_xueshan") !=1 ) 
         {
         return
         notify_fail("��ѻ�����ȵ�������ģ�(answer ����Ѳɽ�ġ�������·�ġ��������ҵ�)\n");
         }
      }
      else 
         { 
         return 
         ::valid_leave(me, dir); 
         }
      return 1;
}




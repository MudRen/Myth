//sgzl
#include <room.h>
inherit ROOM;
 
void create()
{
   set("short", "����");
   set("long", @LONG

СС�������д��СС�Ĺ�Ա���ڷ�æ�Ĺ����ţ�
�м�һ�Ŵ��Ĺ�����
LONG );
set("item_desc",(["book":"
����๲�ϵȳ���ս��ǧƥ����ʱ������á�\n"
]));
 
   set("exits", ([
   "east"  : __DIR__"zoulang",
   "north" : __DIR__"majiu1",
   "south" : __DIR__"yinyanting",
  ]));
 
  set("objects", ([
    __DIR__"npc/jiancheng" : 1,
    __DIR__"npc/dianbu" : 1,
    __DIR__"obj/table" : 1,
  ]));
 

  set("no_fight", 1);
  set("no_magic", 1);

  setup();
}

int valid_leave(object me, string dir)
{
  if (dir == "north" && objectp(present("jian cheng", environment(me)))) 
    {
    if ( me->query("dntg/bmw") !="allow" ) 
         return notify_fail("��ة������ס�����������������صأ�"+ RANK_D->query_respect(me) +"û�»��ǲ�Ҫ��ȥ�˰ɡ�\n");
    else  return  ::valid_leave(me, dir); 
    }
  return 1;
}


//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "����");
set("long", @LONG
    
�յ����ĺ�����ֱ����һ�������ӣ��������
�յ����������ۡ�
LONG );


set("exits", ([
  "up"   : "/d/changan/eastseashore",
]));


/*
set("objects", ([
  __DIR__"obj/shentie" : 1,
]));
*/



setup();
}

void init() {
  object* jingubang;
  object shentie;
  if (present("shen tie",this_object())) return;
  jingubang=children(__DIR__"obj/jingubang");
//  write((string)sizeof(jingubang)+"\n");

  if (sizeof(jingubang)>1) return;
  shentie=new(__DIR__"obj/shentie");
  shentie->move(this_object());
}

int valid_leave(object me, string dir)
{
  object wang;
  string weapon,weapon_id;

  weapon = this_player()->query_temp("weapon");
  if (weapon)  weapon_id=weapon->query("id");

  if(this_player()->query("dntg/donghai")=="hua gan ji" && weapon_id=="jin gu bang")
  {
   wang = new (__DIR__"npc/announcer");
this_player()->set("dntg/donghai","done");
   wang->announce_success (this_player());
   message_vision("$N�ֳֽ𹿰�����һ�ݣ�һ�ɾ�������$N�������\n",this_player());
  }
  return ::valid_leave(me, dir);
}


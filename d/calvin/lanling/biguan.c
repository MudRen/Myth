//Cracked by Roath
inherit ROOM;

int block_cmd(string);
int things(object me);
void create ()
{
  set ("short", "�չ۾���");
  set ("long", @LONG

����������չ۾���,���ص���ʿ����ʱ��Ҳ����������Ƭ��,
����������﷢��ʽ��������

LONG);

  set("exits", ([ /* sizeof() == 4 */
    "south" : "/d/calvin/kezhan",
  
]));
  set("objects", ([ /* sizeof() == 2 */
  
]));
set("no_time", 1);
set("freeze", 1);
  set("no_fight", 1);
set("chat_room",1);
  set("no_magic", 1);
  set("no_upgrade_age",1);

  setup();
  call_other("/obj/board/idle_b", "???");
}
int things(object me)
{
  int i;
  object* inv;
  me = this_player();
inv = all_inventory(me);
  for(i=0; i<sizeof(inv); i++)  {
     if( inv[i]->query_unique() ) {
       message_vision("ͻȻ�䣬$n��һ���׹��ȥ����Ӱ���٣�\n",me,inv[i]);
       destruct(inv[i]);
     }
  }
//   add_action("block_cmd", "", 1);
return 0;
}
int block_cmd(string args)
{
string verb;
verb = query_verb();

    // if (verb == "bian") return 1; // by mon 7/15
    if (verb == "xiudao") return 1;
    if (verb == "exert") return 1;

    return 0;
}

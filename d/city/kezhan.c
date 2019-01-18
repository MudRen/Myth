// kezhan.c

inherit ROOM;
#include <ansi.h>
#include <liwu.h>


int block_cmd(string args); 

void create ()
{
  set ("short","�ϳǿ�ջ");
  set ("long", @LONG

��ҿ�ջ�������������ģ���������ǳ���¡����֮��Ǯ����������
��������ο���ŵ���ѡ��¶������߰������ӣ����̾����˵��ڴ�
�������������ﲻ�����������õ�С�������ػ��д����ķ����͡���
¥���������������ǿͷ���
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"sleep",
  "west" : __DIR__"zhuque-s1",
  "north" : "/d/city/misc/idleroom",
  "up": "/d/wiz/entrance",
]));
//  set("chat_room",1)
  set("objects", ([ /* sizeof() == 2 */
  "/obj/boss/city_waiter" : 1,
  "/adm/npc/liwu" : 1,
  "/d/ourhome/npc/bigeye" : 1,
  ]));


   set("no_time", 1);
  set("no_fight", 1);
  set("no_magic", 1);
        set("freeze",1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
  set("valid_startroom", 1);

/*
  remove_call_out ("drop_liwu");
  call_out ("drop_liwu",10);
*/
  setup();
  call_other("/obj/board/nancheng_b", "???");
}

void init()
{
    add_action("block_cmd", "", 1);
}

int block_cmd(string args)
{
string verb;
verb = query_verb();

    // if (verb == "bian") return 1; // by mon 7/15
    if (verb == "xiudao") return 1;
    if (verb == "teach") return 1;
    if (verb == "cast yueying") return 1;
    if (verb == "exert") return 1;
//      if (verb == "id here") return 1;
//    if (verb == "id") return 1;
    return 0;
}

int valid_leave(object me, string dir)
{
        object mbox,*inv;
        inv = all_inventory(me);
//        if ( sizeof(inv)&& dir == "north" ) return notify_fail("��С����������Ķ���˵����λ�͹٣���������ǰ�뽫���ϵ������ա�\n");

        if ( !me->query_temp("rent_paid") && dir == "east" )
        return notify_fail("��С��������Ц�ص�ס���㣺�Բ��𣬺����ǿ��˵��Է������Ǳ���Ŀ��ˣ�������š�\n");
        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "�㽫���佻�ظ��ʲ\n");
                destruct(mbox);
        }

        return ::valid_leave(me, dir);
}

#if 0
//04.2003 koker �������������֣�������Ϸ��һЩ�����ԡ�
void drop_liwu ()
{
  int i, j;
  object who;
  object *list;

  remove_call_out("drop_liwu");
        call_out("drop_liwu",random(1800)+3600*3); 
  list = users();
  j = 100;
  while  (j--)
  {
    string there;

    i = random(sizeof(list));
    if (!environment(list[i]))
      continue;
    if (!living(list[i]))
      continue;

    who = list[i];

    break;
  }
  if (! who)
    return;
  //who = find_living ("snowcat");
  remove_call_out ("liwu_down");
  call_out ("liwu_down",2,who,"�㿴������е����������\n");
  call_out ("liwu_down",6,who,"������������¡¡����\n");
  call_out ("liwu_down",10,who,"��Ȼ�䣬һ���������$N��ͷ�ϡ�\n");
  remove_call_out ("liwu_drop");
  call_out ("liwu_drop",12,who);
}

void liwu_down (object who, string msg)
{
  message_vision (msg,who);
}

void liwu_drop (object who)
{
  string str = __DIR__;
  object ob;
  string msg;

  ob = new (liwu[random(sizeof(liwu))]);
 
 
  message_vision ("$N���ж���һ�����¡�\n",who);
  msg="��˵"+who->query("name")+"���׵���У�����Ļ����"+ob->name()+"��\n";
CHANNEL_D->do_channel(this_object(),"rumor",msg);
log_file("liwu","["+ctime(time())+"] "+sprintf("%s(%s)�õ���"+ob->name()+"\n", 
    who->query("name"),who->query("id"))); 
  ob->move(who);

}
#endif

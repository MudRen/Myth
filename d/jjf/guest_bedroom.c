// Room: /d/jjf/guest_bedroom.c

#include <ansi.h>

inherit ROOM;
void create ()
{
  set ("short", "�ͷ�");
  set ("long", @LONG

�����������ǵ������д����ܵ��ޱȣ��ѿ�����˵ķ��䲼�õķǳ�
���ʡ���ľ��������һ���ò裬���ż��̵��ġ��ݽ���¯�ﴫ��һ
�������㡣һ�ſ������Ĵ������ű��죬���˲��������˯��
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "��ľ��" : "
�����ϰ��ŷ�ʢ�Ĳ��Ⱥͱ��̵Ĳ�ˮ���㲻�ɵ�������ȥ��(chi)һ�١�
",
  "table" : "
�����ϰ��ŷ�ʢ�Ĳ��Ⱥͱ��̵Ĳ�ˮ���㲻�ɵ�������ȥ��(chi)һ�١�
",
]));
  set("resource", ([
	"water": 1
	]) );
  set("if_bed", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaotong" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
		 "northeast" : __DIR__"front_yard.c",
		 "east" : __DIR__"front_yard2.c",
		 ]));
  set("sleep_room", 1);
  set("no_get", 1);

  setup();
}

void init()
{
  add_action("do_chi", "chi");
  add_action("do_sleep", "sleep");
  add_action("do_get", "get");
}

int do_get(string arg)
{
    object ob;
    string thing, person;

    if(!arg) return notify_fail("��Ҫ��ʲô��\n");
    sscanf(arg, "%s from %s", thing, person);
    if (!person) person=arg;
    if( present("xiao tong", this_object())
    &&  ob=present(person, this_object()))
    {
	if(userp(ob))
	{
	    message_vision(CYN"Сͯ��$N�ȵ�����������$n�˱�����ͣ�\n"NOR, this_player(), ob);
	    return 1;
	}
    }
    return 0;
}

int do_sleep(string arg)
{
  object me=this_player();
  int mypot, mylearned;
  int pot;

  if (me->query("family/family_name") != "������"
  &&  present("xiao tong", this_object()))
  {
	tell_object(me, CYN"Сͯ�ȵ�����������Ŀ����\n"NOR);
	return 1;
  }
  if (me->query("family/master_id") == "cheng yaojin"
   || me->query("family/master_id") == "lao ren")
  {
    mypot=me->query("potential");
    mylearned=me->query("learned_points");
    pot=mypot-mylearned;
    if(pot>100) pot=100;
    if (random(pot+me->query_kar()) > 50)
    {
	message_vision("$N������һ�꣬��ʼ˯����\n",me);
        message_vision("��㱵أ�$N�ƺ������Լ�������һ���ط���\n",me);
	// why need recover here since not real sleep?
	// could be a source of free recover. -- mon
//	me->set("kee", me->query("eff_kee"));
//	me->set("sen", me->query("eff_sen"));
//	me->set("force", me->query("max_force"));
//	me->set("mana", me->query("max_mana"));
	me->move(__DIR__"sleep");
	return 1;
    }
  }
  return 0;
}
int do_chi(string arg)
{
  object me=this_player(), ob;
  int kar=me->query_kar(me);

  if(me->query("family/family_name") != "������"
  && present("xiao tong", this_object()))
	return notify_fail(CYN"Сͯ�ȵ������ǽ������Ŀ����\n"NOR);
  message_vision( "$N����������һ�ڲ�һ�ڲ裬û�����ͳԵ����������ˡ�\n", me);
  me->set("water", me->max_water_capacity());
  me->set("food", me->max_food_capacity());
  if(kar>25) kar=25;
  me->start_busy(random(31-kar));
  return 1;
}

// steamer.c by mes
// updated 9-18-97 pickle

#include <ansi.h>

inherit ROOM;

int do_tao();
int do_get();
void reset();

void create()
{
  set ("short", "����");
  set ("long", @LONG

�ô��һ����������֪Ϊ�������������������(tao)�ɣ�
LONG);
  set("no_fight", 1);
  set("no_magic", 1);
  set("outdoors", 0);
  set("valid_startroom", 1);
  setup();

}
void init()
{
  add_action("do_tao", "tao");
  add_action("do_get", "get");
  add_action("do_get", "ji");
}

int do_get() {return 1;}

int do_tao()
{	
  object me, user, bao;
  string fainter, msg;
  int kee,  mkee;
  
  me=this_player();
  kee=(int)me->query("kee");
  mkee=(int)me->query("max_kee");
  if (random(100)<80) // 20% chance escape
  {		
      if (kee<=mkee/5) {
	me->set_temp("death_msg","�������ˡ�\n");
	bao = new(__DIR__"obj/renroubao.c");
	bao->set("long", "һ�������硢�����ڵ�������ӣ���˵������"
		 + me->query("name") + "�������ģ����滹մ��һЩѪ˿��\n"
		 + "������ζ��֮���������ɵ����˴������Ρ�\n");
	fainter = me->query("wudidong/last_sold_by");
	if (!fainter) {
	    if(bao->move("/d/city/kezhan.c"))
		tell_object("/d/city/kezhan.c",
			"���һ�������ϵ���һ��������ӣ�\n");
	} else {
	  user = find_player(fainter);
	  if (user)
	  {
	    if(!bao->move(user))
		bao->move(environment(user));
	    tell_object(user, "���������������ˡ�\n");
	  } else 
	    if(bao->move("/d/city/kezhan.c"))
		tell_object("/d/city/kezhan.c",
			"���һ�������ϵ���һ��������ӣ�\n");
	}
	//by mon 8/25/97
	me->die();
	return 1;
      }
      else
      {
	  message_vision(RED "һ���һ𣬰�$N�����˻�����\n" NOR, me);
	  me->receive_damage("kee", mkee/5);
	  me->receive_wound("kee", mkee/5-10);
	  switch (random(4)) {
	    case 0: 
		  me->add_maximum_force(-5);
	      msg="������Լ��������ƺ�Ҳ��֮�����ţ�����\n";
	      break;
	    case 1: 
	          me->add_maximum_mana(-5);
	      msg="������Լ��ķ����ƺ�Ҳ��֮�����ţ�����\n";
	      break; 
            default :
	      me->add("combat_exp", 
		      -((int)me->query("combat_exp")/1000));
	      msg="������Լ��ĵ����ƺ�Ҳ��֮�����ţ�����\n";
	      break;
	  }

	  write(msg);
	  me->save();
	  return 1;
	}	
    }
  else
    {
      message_vision(HIG "$Nһҧ������������һ�����˳�ȥ��\n" NOR, me);
      me->move(__DIR__"kitchen");
      message_vision(CYN "$NͻȻ��¯�ϵ����������˳�����ģ��ʮ���Ǳ���\n" NOR, me);
      me->save();
      return 1;
    }
}

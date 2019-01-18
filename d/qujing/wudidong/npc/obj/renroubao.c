// ����� renroubao.c
// 9-16-97 pickle

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("�����", ({ "rou baozi","baozi","bao", "dumpling" }) );
  set_weight(80);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", 
"һ�������硢�����ڵĴ���ӡ�\n");
    set("unit", "��");
    set("value", 0);
    set("name_recognized", "�������");
  }
}

void init()
{
    add_action("do_eat", "eat");
}
int do_eat(string arg)
{
    object me=this_player();
    object baozi=this_object();
    string owner=query("owner");
    int mycap=me->max_food_capacity();
    int myfood=me->query("food");
    string msg, str;

    if(!id(arg)) return 0;
    if(myfood>mycap*9/10) {write("��ûθ�ڣ��Բ�����ô���һ�����ӡ�\n");return 1;}
    message_vision("$N����$n��������ζ�س�����ȥ��\n", me, baozi);
    me->set("food", mycap);
    if(!owner || owner != me->query("id")
    || !query("reward") || (query("type") != "�н���"))
	return 1;
    msg=GRN"��ͻȻ�е�������Щ�仯���ƺ��������ڻ���ʱ�ĵ���������һЩ��\n"NOR;
    tell_object(me, msg);
    me->add("daoxing", query("reward"));
    me->add("wudidong/sell_reward", query("reward"));

    me->add("kill/nkgain", query("reward"));
    str=COMBAT_D->chinese_daoxing((int)query("reward"));
    log_file("npc_kill","["+ctime(time())+"] "+me->query("id")
       +" got "+str +" ���� by selling.\n");
    CHANNEL_D->do_channel(this_object(), "sys",me->query("id")
       +" got "+str +" ���� by selling.");

    destruct(baozi);

    return 1;
}

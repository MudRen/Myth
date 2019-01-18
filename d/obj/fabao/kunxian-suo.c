// kunxian suo
// created by mes, updated 6-30-97 pickle

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit WHIP;
//inherit ITEM;

int ji(string arg);
int determine_success(object me, object victim);
int determine_cost(string var, int limit);
void remove_ding(object me, object victim);

void create()
{
    set_name(RED "������" NOR,({"kunxian suo", "suo", "rope", "kunxiansuo", "kunxian", "fabao"}));
    set_weight(5000);
    if(clonep())
	set_default_object(__FILE__);
    else {
	set("unit","��");
	set("value",0);
	set("is_monitored", 1);
	set("replace_file", "/d/qujing/wudidong/npc/obj/kunxian-fake");
	set("long","һ������ɫ�����ӣ�Ҳ��֪����ʲô���ġ�\n");
    }
    init_whip(20);
    setup();
}

void init()
{
  ::init();
  if (!wizardp(this_player()))
  {
      set("no_drop","��ô�õı�����˶��ϧѽ��\n");
      set("no_give","��ô�õı�������Լ��ðɣ�\n");
      set("no_sell", 1);
  }
}

int ji(string target)
{
    object victim,me=this_player();
    int damage,ratio,mykar=me->query_kar(), dingtime, condition;
    string msg, objname=this_object()->name();
    
    if (this_object()->query("in_use"))
	return notify_fail("�����Ѿ�������ȥ�����ڵ�"+objname+"������һ����ͨ���������ˡ�\n");
    if (!target)
	return notify_fail("�����ö�˭��"+objname+"��\n");
    
    if(!objectp(victim=present(target,environment(me))))
	return notify_fail("����û�� "+target+"��\n");
    if(!living(victim))
	return notify_fail("���Ŀ�겻�ǻ��\n");
    if(!me->is_fighting())
	return notify_fail("ֻ��ս���в��ܼ�"+objname+"��\n");  
    if(victim->query("no_move"))
	return notify_fail("�Է��Ѿ���Ͼ�Թ��ˣ��б�Ҫ��"+objname+"ô��\n");
    if( (int)me->query("mana") < 250)
	return notify_fail("��ķ��������ˣ�\n");
    if( (int)me->query("sen") < 100)
	return notify_fail("��ľ����޷����У�\n");
    msg="$N�ӱ�����һ��"+objname+"��������𣬿��������дʣ�\n";
    msg+="���һ���������зɳ�һ����������$n��ȥ��\n";
    condition=determine_success(me, victim);
    switch(condition)
    {
      case 1:
	msg+=HIR"$n�������̸����ţ���ʱ��æ���ң���֪���롣\n" NOR;
	msg+=CYN"$n��"+objname+CYN"�ķ�����ס�ˣ�\n"NOR;
	victim->set_temp("no_move", 1);
	dingtime=random(mykar);
	if (dingtime < 1) dingtime=1;
	if (wizardp(me) && me->query("env/combat")=="verbose")
	    tell_object(me, GRN ""+victim->name()+"����ס��"+chinese_number(dingtime)+"�롣\n" NOR);
	this_object()->set("in_use", 1);
	call_out("remove_ding", dingtime, me, victim);
	break;
      case 0:
	msg+=HIB"$n����һָ�����һ�����䣡��ֻ��������غ��������$N���С�\n"NOR;
	break;
      case -1:
	msg+=HIB"$n����һָ�����һ�����أ���ֻ����������$N��ס�ˣ�\n"NOR;
	dingtime=random(victim->query_kar());
	if (dingtime<1) dingtime=1;
	me->set_temp("no_move");
	this_object()->set("in_use");
	call_out("remove_ding", dingtime, victim, me);
	break;
      case -2:
	msg+=HIB"$n����һָ�����һ�����գ���ֻ��������غ���������$n���С�\n"NOR;
	this_object()->move(victim);
	break;
    }
    message_vision(msg,me,victim);
    me->add("mana", -determine_cost("mana", 250));
    me->add("sen", -determine_cost("sen", 50));
    return 1;
}
int determine_cost(string var, int limit)
{
    string variable="max_"+var;
    int cost;
    object me=this_player();

    cost=me->query(variable)/4;
    if(cost<limit) cost=limit;
    if(cost>me->query(var)) cost=me->query(var);
    return cost;
}

void remove_ding(object me, object victim)
{
    string msg=CYN"ֻ�������ڿն��𣬸�����"+query("name")+CYN"��\n"NOR;
    this_object()->delete("in_use");
    
    if(!victim) return;

    if (living(victim))
	msg += CYN"$n�ָֻ������ɡ�\n"NOR;
    message_vision(msg, me, victim);
    victim->delete_temp("no_move");
    return;
}
int determine_success(object me, object victim)
{
    int myspells, mydx, victimspells, victimdx;
    int ap, dp, attackfactor, condition;

    myspells=me->query_skill("spells")/10;
    mydx=me->query("daoxing")/1000;
    victimspells=victim->query_skill("spells")/10;
    victimdx=victim->query("daoxing")/1000;

    ap=(mydx+myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
    ap=ap*me->query_kar()/1000;
    dp=(victimdx+victimspells*victimspells*victimspells/3)*victim->query("sen")/victim->query("max_sen");
    dp=dp*victim->query_kar()/1000;

    attackfactor=random(ap+dp);

    if (attackfactor>dp/3) condition=1;
    else if (attackfactor>dp/6) condition=0;
    else if (attackfactor>dp/9) condition=-1;
    else condition=-2;
    return condition;
}

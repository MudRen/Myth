// kunxian suo
// created by mes, updated 6-30-97 pickle

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit WHIP;
//inherit ITEM;

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
//      set("no_drop","��ô�õı�����˶��ϧѽ��\n");
//      set("no_give","��ô�õı�������Լ��ðɣ�\n");
      set("no_sell", 1);
  }
}

int ji(string target)
{
    object victim,me=this_player();
    int damage,ap,dp,ratio,mykar=me->query_kar(), attackfactor, dingtime;
    int myspells, myexp, victimspells, victimexp, mana_cost, sen_cost;
    string msg, objname=this_object()->name(), obj;
    
    if (this_object()->query("in_use")) return notify_fail("�����Ѿ�������ȥ�����ڵ�"+objname+"������һ����ͨ���������ˡ�\n");
    if (!target) return notify_fail("�����ö�˭��"+objname+"��\n");
    victim=present(target,environment(me));
    if(!victim) return notify_fail("����û�� "+target+"��\n");
    if(!living(victim)) return notify_fail("���Ŀ�겻�ǻ��\n");
    if(!me->is_fighting()) return notify_fail("ֻ��ս���в��ܼ�"+objname+"��\n");  
    if(victim->query("no_move")) return notify_fail("�Է��Ѿ���Ͼ�Թ��ˣ��б�Ҫ��"+objname+"ô��\n");
    //    if (member_array( victim, query_enemy()) != -1 )
    //         return notify_fail("�˼���û���㣡\n");
    if( (int)me->query("mana") < 250)
	return notify_fail("��ķ��������ˣ�\n");
    if( (int)me->query("sen") < 100)
	return notify_fail("��ľ����޷����У�\n");
    msg="$N�ӱ�����һ��"+objname+"��������𣬿��������дʣ�\n";
    msg+="���һ���������зɳ�һ����������$n��ȥ��\n";
    myspells=me->query_skill("spells")/10;
    myexp=me->query("combat_exp")/1000;
    victimspells=victim->query_skill("spells")/10;
    victimexp=victim->query("combat_exp")/1000;
    ap=(myexp+myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
    ap=ap*me->query_kar()/1000;
    dp=(victimexp+victimspells*victimspells*victimspells/3)*victim->query("sen")/victim->query("max_sen");
    dp=dp*victim->query_kar()/1000;
    attackfactor=random(ap+dp);
    if (wizardp(me) && me->query("env/combat")=="verbose")
	tell_object(me, GRN "����="+ap+", ����="+dp+", ����="+attackfactor+"��\n" NOR);
    if(attackfactor>dp/3)
    {
	msg+=HIR"$n�������̸����ţ���ʱ��æ���ң���֪���롣\n" NOR;
	msg+=CYN"$n��"+objname+CYN"�ķ�����ס�ˣ�\n"NOR;
	victim->set_temp("no_move", 1);
	dingtime=random(mykar)/2+10;
	if (dingtime < 1) dingtime=1;
	if(dingtime>30) dingtime=30;
	if (wizardp(me) && me->query("env/combat")=="verbose")
	    tell_object(me, GRN ""+victim->name()+"����ס��"+chinese_number(dingtime)+"�롣\n" NOR);
	set("in_use", 1);
	set("suo_victim",victim);
	call_out("remove_ding", dingtime, victim);
    }
    else if(attackfactor>dp/6)
	msg+=HIB"$n����һָ�����һ�����䣡��ֻ��������غ��������$N���С�\n"NOR;
    else if(attackfactor>dp/9)
    {
	msg+=HIB"$n����һָ�����һ�����أ���ֻ����������$N��ס�ˣ�\n"NOR;
	dingtime=random(victim->query_kar())/2+10;
	if (dingtime<1) dingtime=1;
	me->set_temp("no_move");
	set("in_use",1);
	set("suo_victim",me);
	call_out("remove_ding", dingtime, me);
    }
    else
    {
	msg+=HIB"$n����һָ�����һ�����գ���ֻ��������غ���������$n���С�\n"NOR;
	this_object()->move(victim);
    }
    message_vision(msg,me,victim);
    mana_cost=me->query("max_mana")/4;
    if(mana_cost<250) mana_cost=250;
    if(mana_cost>me->query("mana")) mana_cost=me->query("mana");
    sen_cost=me->query("max_sen")/4;
    if(sen_cost<50) sen_cost=50;
    if(sen_cost>me->query("sen")-10) sen_cost=me->query("sen")-10;
    me->add("mana", -mana_cost);
    me->add("sen", -sen_cost);
    return 1;
}

void remove_ding(object victim)
{
    message_vision(CYN"ֻ�������ڿն��𣬸�����"+RED+"������"+CYN"��$N�ָֻ������ɡ�\n" NOR, victim);
    victim->delete_temp("no_move");
    this_object()->delete("in_use");
    return;
}

// remove_ding when suo is destructed.
void remove()
{
    object victim;
    if(query("in_use") && (victim=query("suo_victim")))
	remove_ding(victim);
       ::remove();
}

//Cracked by Roath
// huntian fake
// created by bbs, 4-12-98.


/************************************************************/

// some files to inherit,include, and some functions to declare.
// notice from the declarations that the fabao can be used as a
// weapon alone... at least in this case. :)

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit WHIP;

int ji(string arg);
int determine_success(object me, object victim);
int determine_cost(string var, int limit);
void remove_ding();

/************************************************************/

void create()
{

    // i personally prefer a name with a pretty comprehensive id list
    // that makes it easier on the playrs, particularly those with slow net.
    // another recommendation is that the first id for this item, or any
    // item/npc you ever write, should have a space in it. that way you will
    // avoid a lot of potential trouble.

    set_name(HIR "�����" NOR,({"huntian ling", "ling", "huntianling", "huntian", "fabao"}));
    set_weight(5000);
    if(clonep())
	set_default_object(__FILE__);
    else {
	set("unit","��");
	set("value",0);		//this is mainly to prevent selling

	// these are quite important in my opinion, since we don't want
	// a highhand to get a fabao, then give it to his new character.
	// this fact is particularly important since the fabao is usually
	// unique which means once one person has it, there will not be
  set("value",10000);
  set("no_sell",1);
	// another copy in the mud.

//        set("no_drop","��ô�õı�����˶��ϧѽ��\n")
        set("no_give","��ô�õı�������Լ��ðɣ�\n");
        set("no_sell", 1);

	// this is very important, since as i've stressed many times,
	// we don't want everyone in the mud running around with a ������

	set("is_monitored", 1);

	// this is another very important variable.
	// if this variable is 1 or anything >0 for that matter, then
	// it can be "ji" even when the player is busy. this would be
	// useful for those "rescue" type fabao, such as a piece of
	// paper which when you ji it will take you to another room.
	// it is thus a good insurance for escape during tough fights.

	set("no_busy", 0);

	// i am note THE most sure what the effects would be if we didn't
	// specify this file (of course this file has to exist first).
	// however i do suggest you write it, because it is not that much
	// trouble, and also it might save you much grief later on.
	// note: try to keep the name of the replacement file recognizable
	// and keep it in the same directory if possible

	set("replace_file", "/d/obj/fabao/huntian-fake");

	// there are some standard things for an object which i've ignored
	// here, things such as wield_msg and unwield_msg. if you want your
	// object to be fancier, look in other files for those properties.

	set("long","����һ����ɫ�ĳ����Ҳ��֪���Ǹ�ʲô�õġ�\n");
	set("wield_msg","$N���������һ��$n����ʱȾ����һ����ϼ��\n");
	set("unequip_msg","$N��$nϸ�ĵľ��ϵ�����䡣\n");
    }
    init_whip(10);
    setup();
}

/************************************************************/

// ********make sure your fabao has this function******** 
// this is the function that the "ji" command looks for

int ji(string target)
{
    object victim,me=this_player();
    int damage,ratio,mykar=me->query_kar(), dingtime, condition;
    string msg, objname=this_object()->name();
    
    // sometimes due to the nature of the fabao it can only be used
    // on one person, such as in this case. a rope cannot be tied on
    // more than one person, unless you really push the logic...
    // so this in_use variable specifies whether the fabao is being
    // used or is ready for you to ji.

    if (this_object()->query("in_use"))
	return notify_fail("���ڵ�"+objname+"ֻ��һ����ͨ�ĳ����\n");

    // some fabao require a target, such as this one.
    // (the target is passed in by the "ji" command, if
    // you are interested/suspicious in how it works, you
    // can read /cmds/std/ji.c

    if (!target)
	return notify_fail("�����ö�˭��"+objname+"��\n");

    // if indeed a target is needed we need to test whether the
    // target is around.

    if (!objectp(victim=present(target, environment(me))))
	return notify_fail("����û�� "+target+"��\n");

    // in the case of the ����� it can only be used on living
    // objects, and those who are in battle, ...... this may
    // change according to your fabao's needs.

    if(!living(victim))
	return notify_fail("���Ŀ�겻�ǻ��\n");
    if(!me->is_fighting(victim))
	return notify_fail("ֻ��ս���в��ܼ�"+objname+"��\n");  
    if(victim->query("no_move"))
	return notify_fail("�Է��Ѿ���Ͼ�Թ��ˣ��б�Ҫ��"+objname+"ô��\n");

    // every fabao will have a mana cost and a sen cost.

    if( (int)me->query("mana") < 250)
	return notify_fail("��ķ��������ˣ�\n");
    if( (int)me->query("sen") < 100)
	return notify_fail("��ľ����޷����У�\n");

    // here, the real fun begins. i started this one with an introduction
    // message, showing the rope being "ji".
    // notice the variable "objname". since in the course of the ji command
    // i will have to use the rope's chinese name many times, declaring it
    // up front is much more convenient (in case you change the name) and
    // much cleaner.

    msg="$N����"+objname+"�����������дʣ�\n";
    msg+=objname+"��һ�ź��ư�����$n��\n";

    // here i call a function to determine the success of this ji.
    // i think all fabao should do this, just so the code is cleaner.
    // normally i prefer the following convention, whenever applicable:
    // if condition is 1, then ji is successful.
    // if condition is 0, then ji is unsuccessful but nothing bad happens.
    // if condition is -1, then ji fails AND is bounced back.
    // if condition is -2, then the fabao is taken by the victim.
    // if you can find any more suitable conditions please let me know.

    condition=determine_success(me, victim);

    // the following are just applying those conditions.
    // they will probably vary with each fabao.

    switch(condition)
    {
      case 1:
	msg+=HIR"�����$n��ͷ���Ź��˸����ʵʵ��\n" NOR;
	msg+=CYN"$n��"+objname+CYN"�ķ�����ס�ˣ�\n"NOR;
	victim->set_temp("no_move", 1);
	dingtime=random((int)me->query("mana_factor")*4/5)+1;
	if (dingtime > 60) dingtime=60;
	// for ppl enchant 75 (1500 max_mana), ding 1 minute in the best case.

	// this little if statement let's the wiz know what's going on,
	// if the wiz is using the fabao. this makes for easier debugging.

	if (wizardp(me) && me->query("env/combat")=="verbose")
	    tell_object(me, GRN ""+victim->name()+"����ס��"+chinese_number(dingtime)+"�롣\n" NOR);
	this_object()->set("in_use", 1);
	set("ding_victim",victim);
	call_out("remove_ding", dingtime);
	break;
      case 0:
	msg+=HIB"$n����һָ�����һ�����䣡������籺��һ�������$N���С�\n"NOR;
	break;
      case -1:
	msg+=HIB"$n����һָ�����һ�����أ���ֻ������籷���$N��ס�ˣ�\n"NOR;
	dingtime=random(victim->query("mana_factor")*4/5)+1;
	if (dingtime > 60) dingtime=60;
	me->set_temp("no_move",1);
	this_object()->set("in_use",1);
	set("ding_victim",me);
	call_out("remove_ding", dingtime);
	break;
      case -2:
	msg+=HIB"$n����һָ�����һ�����գ���ֻ������籺��һ��������$n���С�\n"NOR;
	this_object()->move(victim);
	break;
    }

    // shows the message. this is pretty straight forward.

    message_vision(msg,me,victim);

    // i have written a function to determine the cost of mana and sen.
    // again, it makes for cleaner code. i suggest you follow this convention
    // also though it is not THAT necessary.

    me->add("mana", -determine_cost("mana", 250));
    me->add("sen", -determine_cost("sen", 50));
    return 1;
}

/************************************************************/
int determine_success(object me, object victim)
{
    int myspells, mydx, victimspells, victimdx;
    int ap, dp, attackfactor, condition;

    // sometimes you may want to just use what COMBATD.C
    // provides for skill power. if you want an example of
    // that you can look at a cast function in /daemon/class
    // in this case i chose to calculate my own powers,
    // though i don't know why. :P

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

int determine_cost(string var, int limit)
{
    string variable="max_"+var;
    int cost;
    object me=this_player();

    // nothing complicated here i think.

    cost=me->query(variable)/5;
    if(cost<limit) cost=limit;
    if(cost>me->query(var)) cost=me->query(var);
    return cost;
}

/************************************************************/
void remove_ding()
{
    string msg=query("name")+CYN"���һ�����ɿ��ˡ�\n"NOR;
    object victim=query("ding_victim");
    delete("in_use");
    delete("ding_victim");
    if(!victim) return;
    if (living(victim))
	msg += CYN"$N�����˳�����\n"NOR;
    message_vision(msg, victim);
    victim->delete_temp("no_move");
    return;
}
/************************************************************/

// remove ding if ling got destructed (remove called by destruct)
// this is important to prevent target being dinged forever
// if ling got destructed. -- mon 12/11/99
void remove()
{
    remove_ding();
    ::remove();
}


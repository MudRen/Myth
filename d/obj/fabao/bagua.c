// bagua.c ������
// 9-26-97 pickle

/************************************************************/
#include <ansi.h>

inherit ITEM;

int ji(string arg);
int determine_success(object me, object victim);

/************************************************************/

void create()
{
    set_name(BLU "������" NOR,({"tie bagua", "bagua", "tie", "tiebagua", }));
    set_weight(15000);
    if(clonep())
	set_default_object(__FILE__);
    else {
	set("unit","��");
	set("value",10000);
	set("is_monitored", 1);
	set("no_busy", 1);
	set("long","һ��˽��ε�������������Ű���ͼ�Σ��м����Щ����ŤŤ�ķ��ţ���֪ʲô��˼��\n");
	set("material", "iron");
    }
    setup();
}

/************************************************************/

int ji(string target)
{
    object me=this_player(),victim;
    int condition;
    string msg, objname=this_object()->name();
    
    if (!target) victim=me;
    else if(!victim=present(target,environment(me)))
	return notify_fail("����û�� "+target+"��\n");
    if(!living(victim))
	return notify_fail("���Ŀ�겻�ǻ��\n");
    if(!victim->is_fighting())
	return notify_fail("ֻ��ս���в��ܼ�"+objname+"��\n");  
    if( (int)me->query("mana") < 100)
	return notify_fail("��ķ��������ˣ�\n");
    msg=BLU+me->name()+"�ڰ�æ֮�дӻ����ͳ�һ��"+objname+BLU"�����˼������";
    if (victim != me) msg+="ָ��$N";
    msg+="���һ����ȥ����\n";
    condition=determine_success(me,victim);
    switch(condition)
    {
      case 1:
	msg+=BLU"ֻ��"+objname+BLU"����һ�ɺ��̣���$N"
		"��ȥ��������ɢ��ʱ��$N�Ѿ������ˡ�\n"NOR;
	message_vision(msg, victim);
	if (userp(victim)) victim->move(victim->query("startroom"));
	else victim->move("/d/city/kezhan");
	tell_room(environment(victim), victim->name()+"����ӰͻȻ������һ�������С�\n");
	me->start_busy(5);
	break;
      case 0:
	msg+=MAG"��"+objname+MAG"����һ������ɢȥ�ˡ�\n"NOR;
	message_vision(msg, victim);
	break;
    }
    me->set("mana", 0);
    me->set("sen",10); 
    destruct(this_object());
    return 1;
}
/************************************************************/
int determine_success(object me, object victim)
{
    int myspells, victimdx, condition;

    myspells=me->query_skill("spells");
    victimdx=victim->query("daoxing");
    if (!victim->is_busy())
	victimdx=victimdx/4;
    else victimdx=victimdx/2;

    myspells=(myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
    myspells=myspells*victim->query_kar();

    if (random(myspells)>victimdx) condition=1;
    else condition=0;
    return condition;
}
/************************************************************/

// �����«, created by mes
// updated 6-9-97 pickle
 
#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;
 
void create()
{
    set_name(HIC "�����«" NOR,({"qingyu hulu", "qingyu", "hulu", "qingyuhulu", "fabao"}));
    set_weight(5000);
    set_max_encumbrance(50000);
    if(clonep())
	set_default_object(__FILE__);
    else {
	set("unit","ֻ");
	set("value",100);
	set("material","jade");
	set("long","һֻ����ɫ�ĺ�«����֪����ʲô���ģ��������¡�\n");
    }
    set("unique", 1);
    set("replace_file", "/d/obj/fabao/qingyu-fake.c");
    set("is_monitored",1);
    setup();
} 
int ji(string target)
{
    object victim,weapon,hulu,me=this_player(), ob=this_object();
    int damage,ap,dp, myspells, mydx, victimspells, victimdx;
    int ratio, mykar=me->query_kar(), victimkar;
    string msg, obname=(string)ob->query("name"), weaponname;

    hulu=present("qingyu hulu",me);
    if(!target) return notify_fail("�����ö�˭��"+obname+"��\n");
    victim=present(target,environment(me));
    if(!victim) return notify_fail("����û�� "+target+"��\n");
    if(!living(victim)) return notify_fail("���˵ı�������Ҫ�÷���ȥ�ã�\n");
    if(!me->is_fighting()) return notify_fail("ֻ��ս���в��ܼ�"+obname+"��\n");
    if( (int)me->query("mana") < 300 ) return notify_fail("��ôһ��㷨��Ҳ������������\n");
    if( (int)me->query("sen") < 100 ) return notify_fail("���޷����о��������\n");
    weapon = victim->query_temp("weapon"); 
    if(!weapon) return notify_fail("��ĵ��˲�û��ʹ��������\n");
    msg="$N����"+obname+"�����������дʣ�\n";
    msg+="ֻ��һ������������«�����һ����⡣\n";
    me->start_busy(30/mykar);
    victimkar=victim->query_kar();
    myspells=me->query_skill("spells")/10;
    mydx=me->query("daoxing")/1000;
    victimspells=victim->query_skill("spells")/10;
    victimdx=victim->query("daoxing")/1000;
    ap=(mydx+myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
    ap=ap*mykar/1000;
    dp=(victimdx+victimspells*victimspells*victimspells/3)*victim->query("sen")/victim->query("max_sen");
    dp=dp*victimkar/1000;
    if (wizardp(me) && me->query("env/combat")=="verbose")
        tell_object(me, GRN "������"+ap+"�����أ�"+dp+"��\n" NOR);
    if(random(ap+dp)>dp)
    {
	msg+=BLU"$n������ָ����ţ�����"+ weapon->name() +BLU"���«���ȥ�� \n"NOR;
	msg+="$n���е�"+weapon->query("name")+"��$N��ȥ�ˣ�\n"NOR; 
	weapon->unequip();
	if (weapon->query_weight()>hulu->query_max_encumbrance())
	{
	    weaponname=weapon->name();
	    destruct(weapon);
	    msg+=BLU"ֻ��"+weaponname+BLU"��"+obname+BLU"����һ�����̣����Ʈȥ��\n" NOR;
	}
	else weapon->move(hulu);
	me->add("mana", -250);
    }
    else {
	msg+="$n����һ�࣬�������⡣\n";
	me->add("mana", -125);
    }
    message_vision(msg,me,victim);
    return 1;
}






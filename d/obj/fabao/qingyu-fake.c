// �����«, created by mes
// updated 6-9-97 pickle
 
#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;
 
void create()
{
    set_name(HIC "�����«" NOR,({"qingyu hulu", "qingyu", "hulu", "qingyuhulu", "fabao"}));
    set_weight(5000);
    set_max_encumbrance (50000);
    if(clonep())
	set_default_object(__FILE__);
    else {
	set("unit","ֻ");
	set("value",100);
	set("material","jade");
	set("long","һֻ����ɫ�ĺ�«����֪����ʲô���ģ��������¡�\n");
    }
}
int ji(string target)
{
    string objname=this_object()->name();
    object me=this_player(), victim, weapon;

    if(!target) return notify_fail("�����ö�˭��"+objname+"��\n");
    victim=present(target,environment(me));
    if(!victim) return notify_fail("����û�� "+target+"��\n");
    if(!living(victim)) return notify_fail("���˵ı�������Ҫ�÷���ȥ�ã�\n");
    if(!me->is_fighting()) return notify_fail("ֻ��ս���в��ܼ�"+objname+"��\n");
    if( (int)me->query("mana") < 300 ) return notify_fail("��ôһ��㷨��Ҳ������������\n");
    if( (int)me->query("sen") < 100 ) return notify_fail("���޷����о��������\n");
    weapon = victim->query_temp("weapon"); 
    if(!weapon) return notify_fail("��ĵ��˲�û��ʹ��������\n");
    return notify_fail("��������ô���䣬"+objname+"���ǲ�����\n");
}

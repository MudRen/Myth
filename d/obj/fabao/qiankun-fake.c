//Cracked by Roath
// qiankun fake
// created by bbs, 4-12-98.

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name(YEL "Ǭ��Ȧ" NOR,({"qiankun quan", "quan", "qiankunquan", "qiankun"}));
  set_weight(10000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","ֻ");
    set("value",0);
    set("long","һֻ���ִ���ĸֻ����ܽ�ʵ��\n");
    set("wield_msg","$N�ó�һֻ$n�������С�\n");
    set("unequip_msg","$N�����е�$n���뱪Ƥ�ҡ�\n");
  }
  init_hammer(25);
  setup();
}
int ji(string target)
{
    string objname=this_object()->name();
    object me=this_player(), victim;

    if (!target) return notify_fail("�����ö�˭��"+objname+"��\n");
    victim=present(target,environment(me));
    if(!victim) return notify_fail("����û�� "+target+"��\n");
    if(!living(victim)) return notify_fail("���Ŀ�겻�ǻ��\n");
    if(!me->is_fighting()) return notify_fail("ֻ��ս���в��ܼ�"+objname+"��\n");  
    if( (int)me->query("mana") < 250)
        return notify_fail("��ķ��������ˣ�\n");
    if( (int)me->query("sen") < 100)
        return notify_fail("��ľ����޷����У�\n");
    return notify_fail("��������ô���䣬"+objname+"���ǲ�����\n");
}

// kunxian fake
// created by mes, updated 6-30-97 pickle

#include <ansi.h>
#include <weapon.h>
inherit WHIP;
//inherit ITEM;

void create()
{
  set_name(RED "������" NOR,({"kunxian suo", "suo", "rope", "kunxiansuo", "kunxian"}));
  set_weight(5000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","��");
    set("value",0);
    set("long","һ������ɫ�����ӣ�Ҳ��֪����ʲô���ġ�\n");
  }
  init_whip(20);
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
    if(victim->query("no_move")) return notify_fail("�Է��Ѿ���Ͼ�Թ��ˣ��б�Ҫ��"+objname+"ô��\n");
    if( (int)me->query("mana") < 250)
        return notify_fail("��ķ��������ˣ�\n");
    if( (int)me->query("sen") < 100)
        return notify_fail("��ľ����޷����У�\n");
    return notify_fail("��������ô���䣬"+objname+"���ǲ�����\n");
}

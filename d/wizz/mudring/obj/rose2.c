// r-rose.c ��õ��

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(MAG "��õ��" NOR, ({ "pink rose", "rose", "meigui" }));
        set("weight", 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIR "һ��ѩ���͵���õ�壬������һ˿���顣\n" NOR);
                set("value", 5000);
                set("wear_msg", HIM "$N����һЦ���ѻ������ڷ����ϣ�������Ů�·���\n" NOR);
                set("remove_msg", HIM "$N�ѻ����ӷ���ȡ�£����������ţ����ػ��С�\n" NOR);
                set("armor_prop/armor", 50);
                set("no_get", 1);
                set("no_drop", 1);
        }
        setup();
}

void init()
{ 
  add_action("come_life","wen");
  add_action("come_life","smell");
}
        
int come_life(string arg)
{
    object me;
    int i, shen, exp;
    me=this_player();
    shen=me->query("shen");
    exp=me->query("combat_exp");

    if(!arg) return 0;
    if(arg == "rose" || arg == "red rose" ) 
      {
        if(shen > 0) return 0;
        if((-shen) < exp) return 0;
        i = shen + exp;
        i = -i;        
        i = i/50;
        if(i > 130) i = 130;
        me->set("shen", -(exp));
        me->add("combat_exp", 60+i+random(me->query_skill("poison",1)));
        if(me->query("potential") < me->query("max_pot"))
           me->add("potential", random(i));
        me->reincarnate();        
        message_vision(MAG"$N��Сָ������ס��õ�壬����������������š�\n"NOR,me);
        tell_object(me, HIY "�š�����������������ѽ��\n" NOR);
      }
    
    return 1;
}


//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit ITEM;

void init()
{
    set("no_get", "���ò�����������������������(dig)��\n");
    // set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");

    add_action("do_dig", "dig");
    add_action("do_eat", "eat");
}

void create()
{
  set_name(RED "��Ҷ��֥��" NOR, ({"qiong cao","cao"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ���Ϻ�ɫ��С�ݡ�\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  
  // the following line is added by snowcat
  set("is_monitored",1);
  setup();
}
int do_dig(string arg)
{
   object baihe, who, me, where;
   who=this_player();
   me=this_object();
   where=environment(me);

   if( me->query("can_eat"))
     return notify_fail("ʲô��\n");

   if( !arg || (arg!="qiong cao" && arg!="cao"))
     return notify_fail("��Ҫ��ʲô��\n");

   if(who->is_fighting() && who->is_busy())
     return notify_fail("���æ��ûʱ���ղݡ�\n");

   if( baihe=present("bai he")){
     message_vision("�׺׳���һ������$N�����˹�����\n", who);
     baihe->kill_ob(who);
     who->fight_ob(baihe);
     return 1;
   }

     message_vision("$N���Ὣ$n����������\n", who, me);
     me->set("can_eat", 1);
     me->move(who);
     remove_call_out("grow_a");
     remove_call_out("grow_b");
                remove_call_out("grow_c");
                remove_call_out("grow_d");
                remove_call_out("grow_e");
                remove_call_out("grow_f");
                remove_call_out("grow_g");
     where->delete("grow_grass");

   if( !baihe && me->query("eatable")){
     seteuid(getuid());
     baihe=new("/d/penglai/npc/baihe");
     baihe->move(environment(who));
   tell_room(environment(who), "����һ������������г���һֻ�׺�����\n");
   baihe->kill_ob(who);
   who->fight_ob(baihe);
   }
   return 1;
}

int do_eat(string arg)
{
   object me=this_object();
   object who=this_player();
   int force_add, mana_add, howold;
   
     if (!id(arg))
         return notify_fail("��Ҫ��ʲô��\n");
   if( !me->query("can_eat"))
     return notify_fail("��Ҫ��ʲô��\n");


   howold = (int)who->query("mud_age") + (int)who->query("age_modify");

   who->set("food", (int)who->max_food_capacity());
     who->set("water", (int)who->max_water_capacity());

   if( !me->query("eatable")){
     message_vision("$N���̻��ʰ�ؽ�һ��$n������ȥ��\n", who, me);
     destruct(me);
     return 1;
   }

   force_add=5;
   mana_add=5;
   
   message_vision("$N��һ��$n������������˶ǣ����Ϸ�������Ρ�\n", who, me);
   tell_object(who, "�����һ������ֱͨ���ϣ��������º�����ʹ�����������\n");

  who->set("eff_sen", (int)who->query("max_sen"));
  who->set("sen", (int)who->query("max_sen"));
  who->set("eff_gin", (int)who->query("max_gin"));
  who->set("gin", (int)who->query("max_gin"));
  who->set("eff_kee", (int)who->query("max_kee"));
  who->set("kee", (int)who->query("max_kee"));
   
   if( (int)who->query("max_force")< 10*(int)who->query_skill("force")){
         who->add("max_force",force_add);
   }
   if( (int)who->query("max_mana")< 10*(int)who->query_skill("spells")){
                who->add("max_mana",mana_add);
        }
     if( howold > 1382400 ) {
 who->add("age_modify", -864000);
         who->add("age_modify_time", 3);
     }
     destruct(me);
     return 1;
}



void invocation()
{
   object me=this_object();
   int i=200+random(200);
   call_out("grow_a", i, me);
}

int grow_a(object me)
{
   int i=400+random(400);
   tell_room(environment(me), me->name()+"�����س�����һ��СҶ��\n", ({me, me}));
   set_name(RED "һҶ���" NOR, ({"qiong cao","cao"}));
   call_out("grow_b", i, me);
   return 1;
}

int grow_b(object me)
{
        int i=600+random(600);
        tell_room(environment(me), me->name()+"�����س�����һ��СҶ��\n", ({me, me}));
        set_name(RED "��Ҷ���" NOR, ({"qiong cao","cao"}));
        call_out("grow_c", i, me);
        return 1;
}

int grow_c(object me)
{
        int i=800+random(800);
        tell_room(environment(me), me->name()+"�����س�����һ��СҶ��\n", ({me, me}));
        set_name(RED "��Ҷ���" NOR, ({"qiong cao","cao"}));
        call_out("grow_d", i, me);  
        return 1;
}

int grow_d(object me)
{
        int i=1000+random(1000);
        tell_room(environment(me), me->name()+"�����س�����һ��СҶ��\n", ({me, me}));
        set_name(RED "��Ҷ���" NOR, ({"qiong cao","cao"}));
        call_out("grow_e", i, me);  
        return 1;
}

int grow_e(object me)
{
        int i=1200+random(1000);
        tell_room(environment(me), me->name()+"�����س�����һ��СҶ��\n", ({me, me}));
        set_name(RED "��Ҷ���" NOR, ({"qiong cao","cao"}));
        call_out("grow_f", i, me);  
        return 1;
}

int grow_f(object me)
{
        int i=1500+random(1000);
        tell_room(environment(me), me->name()+"�����س�����һ��СҶ��\n", ({me, me}));
        set_name(RED "��Ҷ���" NOR, ({"qiong cao","cao"}));
        call_out("grow_g", i, me);  
        return 1;
}

int grow_g(object me)
{
        int i=2000+random(1000);
        tell_room(environment(me), me->name()+"�����س�����һ��СҶ��\n", ({me, me}));
   tell_room(environment(me), me->name()+"��Χ��������һ�ɺ�⡣\n", ({me, me}));
        set_name(RED "��Ҷ��֥��" NOR, ({"qiong cao","cao"}));
   set("eatable",1);
        return 1;
}


//Cracked by Roath
#include <weapon.h>

inherit STAFF;

int steps;

void create()
{
  set_name("���", ({"yu gan"}));
  set_weight(1000);
  if( clonep() )
  set_default_object(__FILE__);
  else 
    {
    set("long","һ����ͣ�װ(zhuang)���������������(diao)���ˣ����Ϲ����������(ti)�ˣ�\n");
    set("unit", "��");
    set("material", "wood");
    set("value", 2000);
    set("wield_msg", "$N��$n���ڼ���ϡ�\n");
    set("unequip_msg", "$N��$n����������\n");
    }
  set("have_qiuyin",0);
  init_staff(3);
  setup();
}

int init ()
{
  add_action ("do_zhuang", "zhuang");
  add_action ("do_diao", "diao");
  add_action ("do_ti", "ti");
  return 1;
}

int do_zhuang (string arg)
{
  object who=this_player();
  object me=this_object();
  object ob;

  if( (!arg) || (arg != "qiu yin" && arg != "qiuyin" && arg !="���") )
        return notify_fail("��Ҫ��ʲô�����㹳�ϣ�\n");

  ob=present("qiu yin", who);
  if(! present("qiu yin", who)) 
        return notify_fail("������û���ⶫ����\n");

  if(me->query("have_qiuyin")==1)   
        return notify_fail("�����Ѿ�������ˣ������ٴ��ˡ�\n");

  if (who->query_skill("dodge",1)<20)
        return notify_fail("���㱿�ֱ��ŵģ����¿�����������\n");

  message_vision( "$N���㹳�ϴ���һֻ��򾡣\n",who);
  destruct(ob);
  who->start_busy(3);
  me->set("have_qiuyin",1); 

  return 1;  
}



int do_diao (string arg)
{
  object who=this_player();
  object me=this_object();
  object where;

  where=environment(who);

  if( (!arg) || (arg != "fish" && arg != "yu" && arg !="��") )
        return notify_fail("��Ҫ��ʲô��\n");

  if (where->query("can_fish") != 1)
         return notify_fail("���ﲻ�ܵ��㡣\n");

  if(me->query("have_qiuyin")!=1)   
        return notify_fail("����ʲô��û�У���ô����\n");

  if(who->query("is_fishing") ==1)   
        return notify_fail("���Ѿ��������ˡ�\n");

  if(! me->query("equipped") )
         return notify_fail("�����Ѹ�װ���ϲ��ܵ���\n");

  message_vision("$N���㹳ԶԶ�����һ�ף���������ʼ���㡣\n",who);
  steps=0;
  who->set("is_fishing", 1);
  who->start_busy(10);
  remove_call_out ("fishing");
  call_out ("fishing",10,who);
  who->add("sen", -30);

  return 1;
}

int fishing (object who)
{
  object me=this_object();
  string *msg = ({
  "ˮ����һ�㶯��Ҳû�С�\n",
  "��ˮ����һƬ������\n",
  "һ��Сˮ���𽥿����ӡ�\n",
  "���Ӷ��������¡�\n",
  "���ӿ�ʼ�����š�\n",
  "ˮ���ָֻ���ƽ����\n",
});

  if (who->query("sen")<30) 
    {
    message_vision("$Nһ���������еĵ��͵�����ˮ�С�\n",who);
    who->delete("is_fishing");
    destruct(me);
    return 1;
    }

  message_vision(msg[steps],who);
  if (random(2)==1)
    {
    if (steps !=5) steps++;
    else steps=0; 
    }
  who->add("sen", -30);
  who->start_busy(10);
  remove_call_out ("fishing");
  if(who->query("is_fishing") ==1 
       && me->query("equipped") &&  who=environment(me))
     call_out ("fishing",10,who);
  return 1;
}

int do_ti()
{
  object who=this_player();
  object me=this_object();
  object where;
  object fish;

  if(who->query("is_fishing") !=1)   
        return notify_fail("�˲������������𣿻���ʲô����\n");

  set("have_qiuyin",0);
  message_vision("$NͻȻ�����е���˼������ᣬ",who);
  if (steps ==4 && random(2)==1) 
    {
    fish=new("/d/southern/jinghe/obj/fish");
    fish->move(who);
    message_vision("���������һ��"+fish->query("name")+"��\n",who);
    who->delete("is_fishing");
    return 1;
    }

  if (steps ==4 || steps ==3) 
    {
    message_vision("̫��ϧ�ˣ���û���ţ���\n",who);
    who->delete("is_fishing");
    return 1;
    }
  else 
    {
    fish=new("/d/southern/jinghe/obj/trash");
    fish->move(who);
    message_vision("$Nֻ������˳����ģ�����һ�ᣬ������һ"
      +fish->query("unit")+fish->query("name")+"��\n",who);
    who->delete("is_fishing");
    return 1;
    } 
  return 1;
}

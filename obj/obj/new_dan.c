// wan.c ��Ѫ����

#include <ansi.h>

inherit ITEM;

void create()
{
              set_name(HIC"���ɾ�����ң��"NOR, ({ "xiaoyao dan","dan" }) );
        set("long",
  HIG"������ʦ�Ƿ�ʱ�žŰ�ʮһ�����ƶ��ɵ��鵤����ǿ����֮��Ч!\n"NOR);
        set("unit", "��");
        set("weight", 5);
        set("value", 100);
}

void init()
{
        set("no_get","����һ�ɣ��ɵ����ڵ���ˤ�÷��飡\n");
     set("no_give","��ô�õĶ��������������ˣ�\n");
      set("no_drop","��ô�õĶ��������˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("��Ҫ��ʲ�᣿\n");

          if( living( this_player())==0) return 0;

          if( living( this_player())==0) return 0;

        ob=this_player(); 
            ob->set("daoxing",10000);
              ob->set("combat_exp",10000);
            ob->set("potential",6000);
           ob->set("max_force",100);
            ob->set("max_mana",100);
           ob->set("force",100);
           ob->set("mana",100);
           ob->set("maximum_force",100);
          ob->set("maximum_mana",100);
  write(HIR+"�����һ�����ɾ�����ң����ֻ����һ�����������������!����hp��һ�°�...\n"NOR);

        message("vision", HIR + ob->name() + 
  "����һ�����ɾ�����ң����ֻ����һ�����������������!����hp��һ�°�...\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}

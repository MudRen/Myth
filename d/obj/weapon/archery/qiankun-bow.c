#include <weapon.h>

inherit BOW;

void create()
{
        set_name("Ǭ����", ({"qiankun gong", "qiankungong", "bow", "gong", "qiankun"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "Ǭ�������ǳ��ƹ��ܱ�������֮����������ύ\n��׿ͱ��ɶ����뾩�ǣ�Ҳ��������ˡ�\n");
                set("unit", "��");
		set("value", 30000);
                set("wield_msg", "$Nץ��һ��$n���������е�������\n");
                set("material", "steel");
                set("anqi/allow", 1);
                set("anqi/max", 9);
                set("anqi/now", 0);
        }

init_bow(1);
        setup();

}
void init()
{
        add_action("do_install", "install");
        add_action("do_uninstall", "uninstall");
}

int do_install(string arg)
  {
   object me=this_object();
   object who=this_player();
   object aq;
   int remain;

   if( !arg)  return notify_fail("����װʲô��\n");

   aq=present(arg, who);
   if (! present(arg, who)) 
        return notify_fail("������û���ⶫ����\n");
   else if (aq->query("name") == me->query("name") ) return notify_fail("װʲô��\n");
     else if (aq->query("name") != "�����") 
        return notify_fail("������װ����ȥ��\n");
   else if (me->query("anqi/now") == me->query("anqi/max"))
        return notify_fail(me->query("name")+"�Ѿ�װ��������ˡ�\n");
   else if (me->query("anqi/now") >0 && 
            me->query("anqi/type") != aq->query("name") )
        return notify_fail(me->query("name")+"����װ��ͬ�Ķ�����\n");
   else  
     {
     message_vision( "$N��"+me->query("name")+"�Ļ��أ���һ"+aq->query("unit")+aq->query("name")+"װ�˽�ȥ��\n",who);
     who->start_busy(1);
     if (me->query("anqi/now") ==0) me->set("anqi/type",aq->query("name"));
     if (me->query("anqi/now") + aq->query_amount() > me->query("anqi/max")) 
         {
         remain=me->query("anqi/now") + aq->query_amount() - me->query("anqi/max");
         me->set("anqi/now",me->query("anqi/max"));
         me->set("long",me->query("orilong")+"�����Ѿ�װ��" +chinese_number(me->query("anqi/now"))+aq->query("base_unit")+aq->query("name")+"��������uninstall��\n");
         aq->set_amount(remain);
         }
     else 
         {
         me->set("anqi/now",me->query("anqi/now") + aq->query_amount());
         me->set("long",me->query("orilong")+"�����Ѿ�װ��" +chinese_number(me->query("anqi/now"))+aq->query("base_unit")+aq->query("name")+"��������uninstall��\n");
         destruct(aq);
         }
     return 1;
     }
  }

int do_uninstall(string arg)
  {
   object ob;
   object me=this_object();
   object who=this_player();

   if( !this_object()->id(arg) ) return notify_fail("�����ʲô��\n");
   else if (me->query("anqi/now") ==0) return notify_fail(me->query("name")+"����ʲôҲû�С�\n");
   else 
     {
      if (me->query("anqi/type") =="�����") ob=new("/d/obj/weapon/archery/zhentian-arrow");
      ob->set_amount(me->query("anqi/now"));
      ob->move(who);
      me->set("long","Ǭ�������ǳ��ƹ��ܱ�������֮����������ύ\n��׿ͱ��ɶ����뾩�ǣ�Ҳ��������ˡ�\n");
      me->set("anqi/now", 0);
      message_vision("$N��"+me->query("name")+"������һ"+ob->query("unit")+ob->query("name")+"��\n", who);
      who->add_busy(1);
      return 1; 
     }
  }

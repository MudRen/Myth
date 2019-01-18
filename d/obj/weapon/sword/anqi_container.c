//Cracked by Roath
// �����  

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

int do_install(string);
int do_uninstall(string);



void create()
{
   set_name("�����", ({"fenghuang qin","qin","sword"}));
   set_weight(4000);
   if( clonep() ) 
          set_default_object(__FILE__);
   else 
     {
      set("long", "һ����ɫ���ɵĹ��٣�������ֻ����ķ�ˣ�����ȥ��˵Ҳ���ϰ���ı����ˡ�\n");
      set("orilong", "һ����ɫ���ɵĹ��٣�������ֻ����ķ�ˣ�����ȥ��˵Ҳ���ϰ���ı����ˡ�\n");
      set("unit", "��");
      set("value", 3000);
      set("material", "leather");
      set("wield_msg", "$N�ӱ���ժ��һ��$n���������С�\n");
      set("unwield_msg", "$N�������е�$n��С������ı��ر���\n");
      set("anqi/allow", 1);
      set("anqi/max", 20);
      set("anqi/now", 0);
     }
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
   if (aq->query("name") == me->query("name") ) 
                return notify_fail("װ�Լ���\n");
   if (! aq->query("can_install")) 
        	return notify_fail("������̫���ˣ�װ����ȥ��\n");
   if (who->is_busy()) return notify_fail("����æ���ء�\n");
   if (me->query("anqi/now") == me->query("anqi/max"))
        	return notify_fail(me->query("name")+"�Ѿ�װ�������ˡ�\n");
   if (me->query("anqi/now") >0 && me->query("anqi/type") != aq->query("name") )
        	return notify_fail(me->query("name")+"����װ��ͬ����İ�����\n");
   else  
     {
     message_vision( "$N��"+me->query("name")+"�Ļ��أ���һ"
		+aq->query("unit")+aq->query("name")+"װ�˽�ȥ��\n",who);
     me->set("anqi/location",base_name(aq));
     who->start_busy(3);
     if (me->query("anqi/now") ==0) me->set("anqi/type",aq->query("name"));

     if (me->query("anqi/now") + aq->query_amount() > me->query("anqi/max")) 
       {
        remain=me->query("anqi/now") + aq->query_amount() - me->query("anqi/max");
        me->set("anqi/now",me->query("anqi/max"));
        me->set("long",me->query("orilong")+"�����Ѿ�װ��" 
		+chinese_number(me->query("anqi/now"))
		+aq->query("base_unit")+aq->query("name")+"��������uninstall��\n");
        aq->set_amount(remain);
         }
     else 
       {
        me->set("anqi/now",me->query("anqi/now") + aq->query_amount());
        me->set("long",me->query("orilong")+"�����Ѿ�װ��"
		+chinese_number(me->query("anqi/now"))
		+aq->query("base_unit")+aq->query("name")+"��������uninstall��\n");
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
   else if (me->query("anqi/now") ==0) 
		return notify_fail(me->query("name")+"����ʲôҲû�С�\n");
   else 
     {

      ob = new(me->query("anqi/location"));
   if (who->is_busy()) return notify_fail("����æ���ء�\n");
      ob->set_amount(me->query("anqi/now"));
      ob->move(who);
      me->set("long",me->query("orilong"));
      me->set("anqi/now", 0);
      me->delete("anqi/location");
      me->delete("anqi/type");
      message_vision("$N��"+me->query("name")+"������һ"
		+ob->query("unit")+ob->query("name")+"��\n", who);
      who->start_busy(3);
      return 1;               
     }
  }

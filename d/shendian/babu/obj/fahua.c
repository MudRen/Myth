// fahuajing.c
// by repoo

#include <ansi.h>
inherit ITEM;
int close(object me, object ob);
void create()
{
	set_name(RED"������"NOR,({"fahua jing", "book"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���𾭡�\n");
		set("unit", "��");
		set("value", 0);
		set("no_get",1);
      }
	setup();
}

void init()
{
            add_action("do_read","read");
	add_action("do_open", "open");
	add_action("do_enter", "enter");
}

int do_read(string arg)
{
         object obj,me=this_player();
		object ob=this_object();
               string place;
       if( arg != "fahua jing" ) return notify_fail("��Ҫ��ʲô��\n");
   if(this_player()->query_temp("babu/tianshen") != "done")
   return notify_fail("��ɲ��ܶ���\n");
      if(!me->query_temp("fahua_read"))
    {
              place = "/d/shendian/shendian_door.c";
                place = resolve_path(me->query("cwd"), place);
                                obj = load_object(place);
message_vision(HIY"$Nҡͷ���ԵĶ��ţ��˲�������һ�졢����������¥��.....\n"+HIW"ž��"+HIR"���鷢��������"+HIB" ���� "+HIR"�������ڵ��ϡ�\n"NOR, me);
		ob->set("exit",obj);
		ob->move(environment(me));
         me->set_temp("fahua_read",1);
     me->set_temp("fahua/read","done");
    return 1;
      }
     else
     {
     return notify_fail("�����˻�����\n");
    }
}

int do_open(string arg)
{
	object obj,me=this_player();
	object ob=this_object();
	if(!arg || arg!="fahua jing" )return 0;
	if(!ob->query("exit")) 
		return notify_fail("������û�У�\n");
	if(ob->query_temp("opened")) 
		return notify_fail("ͨ������֮��Ĵ����Ѿ�����!\n");
	obj=ob->query("exit");
      if(environment(obj))
                obj = environment(obj);
message_vision("$N���Ὣ�������򿪣����Ѿ�������ͨ������֮��Ĵ��š�\n", me);
      message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+me->query("name")+"��"+HIW" "+MISC_D->find_place(environment(me))+""NOR+YEL" "+"�Ķ�������������ͨ������֮��Ĵ���!\n\n"+NOR,users() );
    me->delete_temp("fahua_read");
	ob->set_temp("opened",1);
        remove_call_out("close");
    call_out("close",60, me,ob);
	return 1;
}

int do_enter(string arg)
{
	object obj,me=this_player();
	object ob=this_object();
	if(!ob->query_temp("opened"))	
		return notify_fail("���Ǻúö��������!!\n");
   if(this_player()->query_temp("babu/tianshen") != "done")
       return notify_fail("��ɲ��ܽ�!!\n");
	obj=ob->query("exit");
          if(environment(obj))
                obj = environment(obj);
        message_vision(HIC"$N�߽��˰˲����������硣\n"NOR, me);
    me->move(obj);
	tell_room(environment(me), HIC"һ���������"+me->name()+"���������\n", ({me}));
        return 1;
}

int close(object me, object ob)
{
	message_vision("$N��ʧ��... ...\n",ob);
		ob->delete_temp("opened");
		ob->delete("exit");
        destruct(ob);
// 98          destruct(me)
// Why destruct player ,,,,mudring@sjsh...
	return 1;
}

//calvin����ҵ�����
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit F_AUTOLOAD;  
inherit ITEM;

object focusobj;

void create()

{
     set_name("����"+BLK"��"+HIW"��"+NOR"��", ({ "ling" }) );
     set_weight(100);
     set("long","����һ������֮�����İ���"+BLK"��"+HIW"��"+NOR"���˵��˲���ƶ�(move)�����á�\n");
     set("value", 0);
     set("material", "steel");
     set("no_drop", "��ô�ѵõ����ƻ������Űɡ�\n");
     set("no_give","��ô�ţ����ʲô���㣿����\n");
     set("no_sell","���ˣ�С������ɱ���㰡��\n");
     set("unit", "��");
}


void init()
{
   add_action("do_move", "move");
   add_action("do_mark", "mark");
}


int do_move()
{
    object me=this_player(); 

  if(me->is_fighting())
     return notify_fail("������㻹����ֻ���п�ȥ�������أ�\n");

  if(me->query("yinyangling")==0)
      me->set("yinyangling",me->query("mud_age"));
  else if(me->query("mud_age")-me->query("yinyangling")>99400)
       {
      me->set("yinyangling",0);
        tell_object(me,HIY"���Ҫ�����ͻȻ�������еİ����������������ڻ���ֻ��������
��������Ϊһ�������ʧ�ڿ����С�\n"NOR);   
        destruct(this_object());
        return 1;
       }


  if( !query("mark_place") ) return notify_fail("���� mark ��Ŀ�ĵ����ϼǺš�\n");

       tell_room(environment(me),HIY+me->query("name")+"˫��΢�գ�����������������䣺"
                        "������������Ǭ���󷨣��ߣ���\n"
                        "һʱ��ɳ����..... "
                        "�����ſ���ʱ,"+me->query("name")+"����Ӱ�Ѿ���ʧ�������ɳ֮��.\n"NOR,me);
 
       tell_object(me,HIY"��˫��΢�գ�����������������䣺"
                        "������������Ǭ���󷨣��ߣ���\n"
                        "�����Ӱ�Ѿ���ʧ�������ɳ֮��.\n"NOR);
        me->move(query("mark_place"));
                message_vision(HIY"$N����ӰͻȻ������һ����֮�С�\n"NOR, me);

       return 1;
}


int do_mark()
{
    object me=this_player(); 

  if(me->is_fighting())
     return notify_fail("������㻹����ֻ���п�ȥ�������أ�\n");

  if(me->query("yinyangling")==0)
      me->set("yinyangling",me->query("mud_age"));
  else if(me->query("mud_age")-me->query("yinyangling")>86400)
       {
      me->set("yinyangling",0);
        tell_object(me,HIY"���Ҫ�����ͻȻ�������еİ����������������ڻ���ֻ��������
��������Ϊһ�������ʧ�ڿ����С�\n"NOR);   
        destruct(this_object());
        return 1;
       }

  set("mark_place",base_name(environment(me)));

  tell_room(environment(me),HIY+me->query("name")+"�������а�������������������˼������\n"NOR,me);
 
  tell_object(me,"��������а�������������������˼������\n"
            +HIY"���Ȼ����������������һ�¡�\n"NOR);
       return 1;
}

int query_autoload() { return 1; }

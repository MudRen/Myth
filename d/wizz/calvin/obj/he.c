#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit F_AUTOLOAD;  
inherit ITEM;

object focusobj;

void create()

{
     set_name(HIG"��"HIY"��"HIW"��"HIM"��"NOR, ({"yueguang baohe","he", "ling" }) );
     set_weight(100);
     set("long","����Ǵ�˵�е�ɽ���������µ��¹ⱦ�У���˵��˲���ƶ�(move)�����á�\n");
                                                                                                             set("value", 2000);
     set("material", "steel");
     set("no_sell", "��ô�ѵõı��ﻹ�����Űɡ�\n");
     set("no_drop", "��ô�ѵõı��ﻹ�����Űɡ�\n");
//     set("no_get","����Ц,�����ѵõı�������һ���������õ��˵�?\n");
     set("unit", "ֻ");
}


void init()
{
   add_action("do_move", "move");
//   add_action("do_mark", "mark");
}


int do_move()
{
    object me=this_player(); 

   if(me->query("kee")<10)
             return notify_fail("�����ڵ�״̬��ô��,�޷�ʹ�ñ��С�\n");
   if(me->query("sen")<10)
             return notify_fail("�����ڵ�״̬��ô��,�޷�ʹ�ñ��С�\n");
  if(me->query_temp("zuochan"))
             return notify_fail("��������������,���޶��ġ�\n");
  if(me->query_temp("no_move"))
             return notify_fail("�����ڱ���ס��,�޷�ʹ�ñ��С�\n");
            if( me->is_busy() ) 
                    return notify_fail("( ����һ��������û����ɣ�����ʹ���¹ⱦ�С�)\n"); 

  if (me->is_fighting() || me->is_busy())
     return notify_fail("������㻹����ֻ���п�ȥ���¹ⱦ���أ�\n");
        if( !wizardp(me) && environment(me)->query("no_move") )
                return notify_fail("���ﲻ׼�ƶ���\n");

  if(me->query("yinyangling")==0)
      me->set("yinyangling",me->query("mud_age"));
  else if(me->query("mud_age")-me->query("yinyangling")>86400)
       {
      me->set("yinyangling",0);
        tell_object(me,HIY"���Ҫ�����ͻȻ�������е��¹ⱦ���������ڻ���ֻ��������
��������Ϊһ�������ʧ�ڿ����С�\n"NOR);   
        destruct(this_object());
        return 1;
       }


//  if( !query("mark_place") ) return notify_fail("���� mark ��Ŀ�ĵ����ϼǺš�\n");

       tell_room(environment(me),me->query("name")+"˫��΢�գ���������ʱ�մ����䣺"
                        "������������Ǭ���󷨣��ߣ���\n"
                        "�����ſ���ʱ,"+me->query("name")+"����Ӱ�Ѿ���ʧ�������ɳ֮��.\n"NOR,me);
 
       tell_object(me,HIY"��˫��΢�գ���������ʱ�մ����䣺"
                        "������������Ǭ���󷨣��ߣ���\n"
                        "�����Ӱ�Ѿ���ʧ�������ɳ֮��.\n"NOR);
        me->move("/d/changan/bridge");
                message_vision(HIY"$N����ӰͻȻ������һ����֮�С�\n"NOR, me);

       return 1;
}


/*
int do_mark()
{
    object me=this_player(); 

  if(me->is_fighting())
     return notify_fail("������㻹����ֻ���п�ȥ���¹ⱦ���أ�\n");

  if(me->query("yinyangling")==0)
      me->set("yinyangling",me->query("mud_age"));
  else if(me->query("mud_age")-me->query("yinyangling")>86400)
       {
      me->set("yinyangling",0);
        tell_object(me,HIY"���Ҫ�����ͻȻ�������е��¹ⱦ���������ڻ���ֻ��������
��������Ϊһ�������ʧ�ڿ����С�\n"NOR);   
        destruct(this_object());
        return 1;
       }

  set("mark_place",base_name(environment(me)));

  tell_room(environment(me),HIY+me->query("name")+"���������¹ⱦ�У������������˼������\n"NOR,me);
 
  tell_object(me,"����������¹ⱦ�У������������˼������\n"
            +HIY"���Ȼ���������¹ⱦ�п���һ��,��û��������Ķ������ֱ������ˡ�\n"NOR);
       return 1;
}

*/
int query_autoload() { return 1; }

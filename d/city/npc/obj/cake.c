// by night
// fid �޸�

#include <ansi.h>


inherit ITEM; 

int do_eat(string);
void init();
void init()
{
  if(!wizardp(this_player())) {
    set("no_get","������ڵ��ϾͲ��ܳ��ˣ�\n");
    set("no_give","�������յ��Ⱑ����ô���������أ�\n");
    set("no_drop","���յ������˶��ϧѽ��\n");
    set("no_sell","���Ƕ����ģ��������ˡ�\n");
  }
  add_action("do_eat", "chi"); 
  add_action("do_wish", "wish");
  }

void create()
{
  set_name( HIY "���յ���" NOR , ({"shengri dangao","cake", "dangao"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ��߼����͵��⣬��һ�������(chi)�����������м����֣�\n\n"
HIR"                  ף�����տ���\n"NOR);
    set("value", 10000);
    set("no_beg",1);
    set("no_get",1);
    set("no_give",1);
    set("no_steal",1);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me, ob;
  int age,gain;
   me = this_player(); 
    //vkar=(int)me->query("age"); 
    //�����ø�Ե�жϸ�����������ڸ�Ϊ����
   age=(int)me->query("age");
   if (age<20) gain=5000;
   else if(age<30) gain=6000;
   else if(age<40) gain=7000;
   else if(age<50) gain=8000;
   else if(age<60) gain=9000;
   else if(age<70) gain=10000;
   else gain=11000;
   
  
  if (!id(arg))
            return notify_fail("��Ҫ��ʲô��\n");
  if(this_object()->query("owner")!=this_player()->query("id"))
           return notify_fail("�������������յ���Ŷ?\n");
  if (!me->query("fired") )
  return notify_fail("��̫���ˣ������������ȣ�\n");
  if (!me->query("wished") ){
       tell_object(me,"�Ե���ǰ�����Ը(wish)�ɡ�\n"
"������ԸҪ��ѧ(exp)��Ǳ��(pot)�����ߵ���(dx)��\n");
       return 1; 
}
if(!me->query_temp("marks")) {
        tell_object(me,"�Ե���ǰ�����Ը(wish)�ɡ�\n"
"������ԸҪ��ѧ(exp)��Ǳ��(pot)�����ߵ���(dx)��\n");
       return 1; 
}
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity()); 
  if (me->query("gender")=="����")
  message_vision(HIG "$N�������ڵذѵ��������ȥ�����˸����á�\n\n" NOR, me);  
  else if(me->query("gender")=="Ů��")
  message_vision(HIG "$N�����㽵س��µ��⣬���Ϸ���һĨ���Ρ�\n\n" NOR, me); 
  message_vision(HIG "$N��Ը��ʵ������\n" NOR, me);  
    me->set("fired",0);  
    me->add("cigar_bug/daogao",1);  
       
   if ( me->query_temp("marks/exp") ){ 
   
    me->add("combat_exp",gain); 
    me->set("wished",0);
    me->set_temp("marks/exp",0); 
    destruct(this_object());
    return 1;
         }
      if ( me->query_temp("marks/pot") ){ 
   
    me->add("potential",gain);
    me->set("wished",0);
    me->set_temp("marks/pot",0); 
    destruct(this_object());
    return 1;
         }
    
      if ( me->query_temp("marks/dx") ){ 
   
    me->add("daoxing",gain);
    me->set("wished",0);
    me->set_temp("marks/force",0); 
    destruct(this_object());
    return 1;
          } 
 
}
 
int do_wish(string arg) 
{
    object me;
    me = this_player();
  if(!me->query("fired"))
    return notify_fail("����û����Ը������Ŷ��\n");
  if (arg=="pot") { 
  message_vision(HIY "$N�����۾���ĬĬ�����˸�Ը��\n" NOR, me);  

    me->set("wished",1);
    me->delete_temp("marks");
    me->set_temp("marks/pot",1);
    return 1;
    }  
  if (arg=="exp") { 
  message_vision(HIY "$N�����۾���ĬĬ�����˸�Ը��\n" NOR, me);  
me->start_busy(random(5));
    me->set("wished",1);   
     me->delete_temp("marks");
      me->set_temp("marks/exp",1);
    return 1;
    } 
  if (arg=="dx") {
  message_vision(HIY "$N�����۾���ĬĬ�����˸�Ը��\n" NOR, me);  
me->start_busy(random(5));
    me->set("wished",1);
     me->delete_temp("marks");
    me->set_temp("marks/dx",1);
    return 1;
    } 
 
  return notify_fail("������ʲôԸ��������ԸҪ��ѧ(exp)��Ǳ��(pot)�����ߵ���(dx)��\n"); 
}

void owner_is_killed()
{
        object me = this_player();
        write(HIM"ֻ��һ����������...ʬ����ʲô������ʧ�ˡ�\n"NOR);
        destruct(this_object());
        return;
}


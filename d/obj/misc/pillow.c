
#include <ansi.h>

inherit ITEM;

void create() {
  set_name("������", ({"huangliang zhen","pillow","zhen"}));
  set("long","һֻ�廨��ͷ���ഫ����¬��������ߣ����˸����Ρ�\n");
  set_weight(3000);
  if( clonep() )
          set_default_object(__FILE__);
  else {
          set("unit", "ֻ");
          set("value", 2500);
          set("material", "cloth");
  }
  setup();
}

int goto_dream(object me)
{
    object env;
    
    if(!me) return 0;
    
    if(env=environment(me))
      tell_object(env,"\n"+HIY+me->name()+"ӵ��"+name()+
	      "���������ε����磮����\n\n"NOR);
    return 1;
}


void pillow_destruct()
{
    destruct(this_object());
}

/*
void init() {
  add_action("do_sleep","sleep");
}

int do_sleep(string arg)
{
  object ob=this_object(),me=this_player();
  object env = environment(me);
        
  if (arg!="pillow" && arg!="zhen" && arg!="zhen tou") return 0;
  if( !env->query("sleep_room") &&
      !me->query_temp("force_sleep") )
          return notify_fail("���ﲻ��˯���ĵط���\n");
  if (me->is_busy())
          return notify_fail("����æ���أ�\n");
  if( me->is_fighting() )
          return notify_fail("ս���в���˯����\n");
  if ((time()-me->query("last_sleep"))<90)
          return notify_fail("���˯��һ��, �Ȼ��ɡ� \n");
  message_vision(HIY"$Nӵ����ͷ���������ε����磮����\n"NOR,me);
  me->move("/d/ourhome/honglou/kat");
  me->set("dream_place",(string)env);
  return 1;
}
*/

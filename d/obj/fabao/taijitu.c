
#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void create()
{
  set_name("̫��ͼ", ({"taiji tu", "tu", "fabao"}));
  set_weight(1000);
  if(clonep())
     set_default_object(__FILE__);
  else {
    set("long", @LONG
Ԫʼ����������̫֮��ͼ��
�÷���ji <name> on <direction>
      qi <name>

LONG );
 
  set("unit", "��");
  set("value", 0);
  set("no_put",1);
  set("no_sell",1);
  set("no_drop",1);
  set("no_give",1);

  set("replace_file", "/obj/money/gold");
        }
  set("is_monitored", 1);
  setup();
}

void init()
{
  add_action("do_ji","ji");
  add_action("do_shou","qi");
  check_owner();

}

int do_ji (string arg)
{
  object me = this_player();
  string fabaoname,dir,dest;
  object fabao;
  object env=environment(me);
//  mapping exits=env->query("exits");

  if( !wizardp(me) && environment(me)->query("no_magic") )
        return notify_fail("�����ֹ��������\n");
  if( !arg ) return notify_fail("��Ҫ������������\n");

  // Check if correct format is followed
  if( sscanf(arg, "%s on %s", fabaoname, dir)!=2 )
        return notify_fail("ָ���ʽ : ji <��������> on <����>\n");

  fabao=present(fabaoname, me);
  if(fabao!=this_object()) {write("strange...\n");return 0;}
  dest = environment(me)->query("exits/"+dir);
  if (fabao->query("being_used")) {
    write("���Ѿ�����̫��ͼ�ˡ�\n");
    return 1;
  }

  if (me->is_busy())
    return notify_fail("����һ��������û����ɣ���Ͼ�����������\n");
  if(!dest) return notify_fail("�������û��·����\n");
        
  if(me->is_fighting())
    return notify_fail("����æ�Ŵ�ܣ�û�ռ�̫��ͼ��\n");
  if( (int)me->query("mana") < 500 )
     return notify_fail("��ķ������ܿ���̫��ͼ��\n");
  if( (int)me->query("sen") < 200 )
     return notify_fail("��ľ����㣬���Ѽ�Ԧ̫��ͼ��\n");

  message_vision(HIC"\n$N΢΢һЦ��������һ����չ����̫��ͼ��\n"+
      "�������ǰһ�����·������������Դ��\n\n"NOR,me);

  me->add("mana",-100);
  me->receive_damage("sen", 100);
  
  env->set("altered_dir",dir);
  env->set("old_room",dest);

  env->set("exits/"+dir,__DIR__"taijituroom");
  fabao->set("start",env);
  
  if (me->move(__DIR__"taijituroom")) {
    if (me->ride()) me->ride()->move(environment(me));
    write("\n");
    environment(me)->set("old_room",env);
    env=environment(me);
    env->set("exits",([dir:dest]));
    env->set("host",me);
  }  
  me->start_busy(1+random(3));
  fabao->set("being_used",1);
  return 1;

}

int do_shou(string arg) {
  object me=this_player();
  object bridge,env=environment(me),fabao=this_object();
  object env1;

  if (!arg) return 0;
  if (present(arg,me)!=fabao) {
    write("strange...\n");
    return 1;
  }

  if (!fabao->query("being_used")) {
    write("̫��ͼ�úõ������ء�\n"); 
    return 1;
  }
  
  
  if (!bridge=find_object(__DIR__"taijituroom")) {
     write("������̫��ͼ��\n");
     fabao->delete("being_used");
     return 1;
  }

  if (env=bridge) {
    if (env1=fabao->query("start"))
       env1->set("exits/"+env1->query("altered_dir"),env1->query("old_room"));
    bridge->explode();
    write("������̫��ͼ��\n");
    fabao->delete("being_used");
    return 1;
  }
  if (bridge->is_clear()) {
    if (env1=fabao->query("start"))
       env1->set("exits/"+env1->query("altered_dir"),env1->query("old_room"));
    write("������̫��ͼ��\n");
    fabao->delete("being_used");
    destruct(bridge);
    return 1;
  }

  return notify_fail("ͼ�����ˣ��ղ��ã�\n");
}
  

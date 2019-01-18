
#include <ansi.h>

inherit ROOM;
void drunk();
int effect();
void create ()
{
  set ("short", "�ƽ�");
  set ("long", @LONG

һ���ܲ�͸��ĵؽѣ�������һ���ž�̳������װ�ľ���
����������˼֮���Ѳ��ѵ���ĸ�ɾ��ˡ���һ�߽�������
���þ����˱ǣ���Ȼ�Ǻþơ�
LONG);

  set("exits", ([
        "up"  : __DIR__"donglang",
      ]));

   set("objects",([
    __DIR__"npc/obj/jiutan" :4,
  ]));

//  set(no_magic,1)
  set("no_clean_up", 1);
  setup();
//  drunk();
}

void drunk() {
  object *user;
  user=all_inventory(this_object());
  for (int i=0;i<sizeof(user);i++)
    if(living(user[i])) {
       user[i]->apply_condition("drunk",
            (int)user[i]->query_condition("drunk")+50); 
       tell_object(user[i],"���㴼���㲻��ƮȻ����\n");
     }
  remove_call_out("drunk");
  if (sizeof(user))  call_out("drunk",60);
}

void init() {
  add_action("do_fill","fill");
  this_player()->delete_temp("yaochi_fill");

  if (this_player()->query_temp("yaochi_open") && 
      this_player()->query("dntg/yaochi")!="done") 
     call_out("announce",2,this_player());
  drunk();
}

void announce(object me) {
  
  if (me->query("dntg/yaochi")=="done") return;
  tell_object(me,HIC"���ŵ��ɾƵ���ζ��ȫ������˵��������̩�����ø�������������\n"NOR);
  message("channel:rumor", HIM + "��ҥ�ԡ�ĳ�ˣ���˵"+
     me->query("name")+"������أ�͵������ĸ������ɾơ�\n"NOR,users());
//  me->add("gift_modify/con",2);

  me->set("dntg/yaochi","done");
}

int do_fill(string arg)
{
   string liquid_name;
   string liquid_type;
   object me=this_player();
   object jiudai;

   if( !living(this_player()))  return 1;
   if (!arg || !jiudai=present(arg,me)) return notify_fail("װ��ʲô��\n");

   if( this_player()->is_busy() )
         return notify_fail("����һ��������û����ɡ�\n");
  if (!inherits(F_LIQUID,jiudai)) return notify_fail(jiudai->query("name")+"��������װ�ƣ�\n");
   if(me->query_temp("yaochi_fill")) 
      return notify_fail("���Ĳ��������󣬻��Ǽ��þ��հɡ�\n");
   me->set_temp("yaochi_fill",1);

   liquid_name = YEL"�ɾ�"NOR;
   liquid_type = "alcohol";

   if(jiudai->query("liquid/remaining") )
      message_vision("$N��"+jiudai->name()+"��ʣ�µ�"+
        jiudai->query("liquid/name")+"������",me);
   message_vision("$N��"+jiudai->name()+"װ��"+liquid_name+"��\n",me);

   if( this_player()->is_fighting() ) this_player()->start_busy(2);

   jiudai->set("liquid/type", liquid_type);
   jiudai->set("liquid/name", liquid_name);
   jiudai->set("liquid/remaining", query("max_liquid"));
   jiudai->set("liquid/drink_func", (:effect:));

   return 1;
}

int effect() {
  object me=this_player();
  int max=(int)me->query("max_force")*2;
  this_player()->apply_condition("drunk",
     (int)this_player()->query_condition("drunk")+5);
  message_vision(HIG"$N�е�������������������ԴԴ������\n"NOR,me);
  
  me->add("force",200+random(100));
  if (me->query("force")>max) me->set("force",max);

  return 1;
}





//Cracked by Roath

#include <ansi.h>

inherit ROOM;
// day_phase is an array of mappings of the following type:
// length:time_msg:desc_msg:event_fun
// %d:%s:%s:%s

static mapping *day_phase = NATURE_D->query_day_phase();

string dest=__DIR__"eastseashore";

void flood();
void _flood(object);
void strip(object);

int get_current_day_phase() {
    // ref. /adm/daemons/natured.c:init_day_phase()
    mixed *local = localtime(time()*60);
    int t = local[2] * 60 + local[1];
    int i;
    for (i=0; i<sizeof(day_phase); i++)
        if (t>=day_phase[i]["length"])
            t -= (int)day_phase[i]["length"];
        else
            break;
    return (i==0 ? sizeof(day_phase)-1 : i-1);
}


void create ()
{
  set ("short", "������̲");
  set ("long", @LONG

ҹ��Ĵ󺣣���ˮ��ī����ƽ�˾����¹��ں����ϻ�
��һ�����⣬�������ĺ���������һ˿������Ȼ����
�������ŵı����£���ˮ�������ӿ��ˮ��¡¡��
�ƺ�Ҫ��һ���������ɡ�

LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"eastseashore",
  "east" : __DIR__"beach",
]));

  setup();
  call_out("flood",21+random(20));
}

void flood() {
  object *inv=all_inventory(this_object());
  call_out("flood",21+random(20));

  tell_room(this_object(),"�ǳ��ˣ���ˮ������������ľ޺����������ڰ�����������\n");
  for (int i=0;i<sizeof(inv);i++)
    if (userp(inv[i])) _flood(inv[i]);
}

void _flood(object me) {
  object corpse;
  if (!me->query("life/live_forever")) {
    message_vision("$N����ˮ�����ˡ�\n\n",me);
    me->set_temp("death_msg","�������������ˡ�\n");
// strip(me);
    me->die();
    me->delete_temp("death_msg");
    corpse=present("corpse",this_object());
    if (corpse && corpse->move(dest))
        tell_room(environment(corpse),"��ˮ��"+corpse->name()+"���ϰ�����\n");
    return;
   }
  if (random(me->query_kar())>8) {
    message_vision("$Nһ����������һԾ�����ڽ�ʯ�ϣ���ˮ��Х�Ŵ�$N�������������գ�\n\n",me);
    return;
  }
  message_vision("$N����ˮ�����ˡ�\n\n",me);
// strip(me);
  me->unconcious();
  if (me->move(dest))
    tell_room(environment(me),"��ˮ��"+me->name()+"���ϰ�����\n");
}

void strip(object me) {
  object *inv=deep_inventory(me);

  me->set("water", (int)me->max_water_capacity());
  if (!inv) return;
  for (int i=0;i<sizeof(inv);i++)
    if (userp(inv[i])) inv[i]->move(dest);
    else destruct(inv[i]);
  
}
void init() {
  int phase = NATURE_D->query_current_day_phase();
    if (phase < 6) return;
    add_action("do_fill","fill");
}

int do_fill(string arg) {
    object stone;
    object me=this_player();
  int phase = NATURE_D->query_current_day_phase();
    int r;

    if (!arg && arg!="hai" && arg!="sea") 
       return notify_fail("��Ҫ��ʲô��\n");

/*
    if (phase < 6) 
        remove_action("do_fill","fill");
*/
 
    if (me->is_fighting() || me->is_busy() ) {
        write("����æ���ء�\n");
        return 1;
    }   
    if (me->query("kee")<500 || me->query("sen")<500 ||
        me->query("mana") <1000 || me->query("force")<1000) {
            write("��̫���ˣ�����Ъ����ɡ�\n");
        return 1;
    }
        
  stone=present("shi kuai",me);
  if (!stone || stone->query_amount()==0)
  {
       write("����ʲô�������\n");
       return 1;
    }
    message_vision("$N�ӻ����ͳ�һ��ʯͷͶ�뺣�У�ʯ��Ѹ�ٳ���ˮ�У���ˮ����û�����㡣\n",me);
    // mon 7/28/99
    if(stone->query("fill_sea")) {
	write("���۵����ᱳʹ�����ֱ۶�̧��������\n\n");
	r=random(4)+1;
	if (r>stone->query_amount()) r=stone->query_amount();
	me->add("potential",me->query_skill("spells")/10);
    }
    stone->add_amount(-1);
    me->start_busy(3+random(3));
    return 1;
}
    

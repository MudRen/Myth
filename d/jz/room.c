inherit ROOM;
void create ()
{
  set ("short", "���");
 set ("long", "����С��һ�䷿�ӣ���������һ�鷢�Ƶ��Ű壬���������ŵģ�\n����̨���Ѿ��������ˡ���ǰֻ��һλ���ߣ�����������˳���Զ��\n�ˡ�");
  set ("exits", ([]));
  set ("outdoors", 1);
  set ("no_clean_up", 1);
  set ("sleep_room",1);
  set ("if_bed",1);
  set("exits", (["east"         : __DIR__"dingan-2",]));
  set ("objects", ([ __DIR__"npc/oldman"  : 1,]) );
  setup();
}
/*
void init()
{
object who=this_player();
if( (string)who->query("gender")=="����" || (string)who->query("gender")=="Ů��" )
{
call_out("heal_up", 1, who);
}
remove_call_out("sounding");
call_out("sounding", random(10), this_object());
}
int sounding(object where)
{
string *msgs=({
"����û���˵�������泩��\n",
});
tell_room (where,msgs[random(sizeof(msgs))]);
}
int heal_up(object who)
{
if( !who || environment(who) != this_object() )
{
return 1;
}
who->set("eff_gin", (int)who->query("max_gin"));
who->set("eff_kee", (int)who->query("max_kee"));
who->set("eff_sen", (int)who->query("max_sen"));
message_vision("һ������ӿ��$N��$N�������˼�������\n", who);
write("������Լ��ľ�����Ѫһ���Ӷ��ָ��ˡ�\n");
if( (int)who->query("food") < (int)who->max_food_capacity() )
who->set("food", (int)who->max_food_capacity());
if( (int)who->query("water")< (int)who->max_water_capacity())
who->set("water", (int)who->max_water_capacity());
return 1;
}
*/

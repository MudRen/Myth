// sgzl
#include <ansi.h>
#define NAME "��Ԫ˧"

inherit NPC;

void create()
{
  set_name(NAME, ({"ma yuanshuai"}));
  set("male", "����");
  set("age", 23);
  set("long", "һֻ����\n");
  set("combat_exp", 1000000);
  set("daoxing", 1000000);

  

  set_skill("dodge", 120);
  set_skill("parry", 120);
  set_skill("dragonstep", 120);
  map_skill("dodge", "dragonstep");
  set("force", 900);
  set("max_force", 900);
  set("force_factor", 10);

  setup();
}

void init()
{
  ::init();
}

void announce_success(object who)
{
  int i;

  i = random(500);
//  message_vision (HIY NAME+"���˹�����\n" NOR,who);
  who->add("dntg/number",1);
  who->set("dntg/huaguo","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"ն�˰�ռ����ˮ������ħͷ��˳�����������칬��һ�أ�");
  command("chat �Ӵ���ʮ���������Ӧ��"+who->query("name")+"Ϊ������ʱ�����ǲ��");
  tell_object(who,"��Ӯ����"+chinese_number(3)+"��"+chinese_number(i/4)+"��"+chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  message_vision (HIY NAME+"��ͷ�����Ķ�$N˵���������������ֵܵ�һ���С��˼�����ɾ��⡣\n" NOR,who);
  tell_object(who,"��Ԫ˧����һ��ʯͷ���ӡ�\n");
  who->save();
}

void refuse_player(object who)
{
  string name;
  name = who->name();

  message_vision (HIY NAME+"ͻȻ���˹���$Nҡҡͷ��"+
                  "��������ѡ������û�±������ҡ�\n" NOR,who);
  message_vision (HIY "˵��"+NAME+"���Ҵҵ��뿪�ˡ�\n" NOR,who);
}

��

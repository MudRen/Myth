// sgzl
#include <ansi.h>
#define NAME "����Ԫ˧"

inherit NPC;

void create()
{
  set_name(NAME, ({"tian peng yuan shuai"}));
  set("male", "����");
  set("age", 23);

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
  who->add("dntg/number",1);
  who->add("daoxing",i+3000);
  command("chat ��"+who->query("name")+"���㲻�ú�����������£�ȴ����������ң����ҵ����Ϲ٣�����������ƣ���");
  tell_object(who,"��Ӯ����"+chinese_number(3)+"��"+chinese_number(i/4)+"��"+chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}

��

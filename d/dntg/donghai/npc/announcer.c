// sgzl
#include <ansi.h>
#define NAME "��������"

inherit NPC;

void create()
{
  set_name(NAME, ({"donghai longwang"}));
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
  who->set("dntg/donghai","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"�㾹�������������Ķ��������������Ҳ�ȥ�����ǰ���㣡");
  tell_object(who,"��Ӯ����"+chinese_number(3)+"��"+chinese_number(i/4)+"��"+chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}

��

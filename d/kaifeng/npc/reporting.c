
#define DEBUG 0

void informing (object me, object who, string str)
{
// if (! DEBUG) return;

//  object snowcat = find_player ("snowcat");
//
//  str = replace_string (str, "$N", me->query("name"));
//  str = replace_string (str, "$n", who->query("name"));
//  if (snowcat && wizardp(snowcat))
//    tell_object (snowcat, " �� "+str);
}

void reporting (object who, string reason, int points, string name)
{
  string str = reason+"�õ���"+to_chinese(points)+"��"+name+"��\n";

// if (! DEBUG) return;

//  object snowcat = find_player ("snowcat");
//
//  if (snowcat && wizardp(snowcat))
//    tell_object (snowcat, " �� "+who->query("name")+str);
}


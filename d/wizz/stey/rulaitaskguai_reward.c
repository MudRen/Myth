string give_reward(object me) {
  mapping skill=me->query_skills();
  string *skillnames;
  string selected,msg;
  int level, inc=1,pot;

  if (!skill) return "none";

  skillnames=keys(skill);
  selected=skillnames[random(sizeof(skillnames))];

  // mon 3/25/99
  level=skill[selected];
    me->set_skill(selected,level+1);
//      pot=level*level*4;
//      me->improve_skill(selected,pot);
//    tell_object(me,"��õ���"+chinese_number(pot)+"��"+ to_chinese(selected) + "��\n");
    tell_object(me,"��õ���һ��"+ to_chinese(selected) + "��\n");
    return selected;
}

// gender.c

string gender_self(string sex)
{
// modify by mudring
     return "��";
}

string gender_pronoun(string sex)
{
    switch(sex)
    {
        case "������":  return "��";    break;
        case "����":    return "��";    break;
        case "Ů��":    return "��";    break;
        case "����":
        case "����":    return "��";    break;
        default: return "��";
    }
}

